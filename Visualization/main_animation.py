from manim import *
import numpy as np

config.media_dir = "./media"
config.video_dir = "./media/videos"
config.images_dir = "./media/images"
config.verbosity = "WARNING"

config.format = "mp4"
config.pixel_height = 1080
config.pixel_width = 1920
config.frame_rate = 30
config.renderer = "cairo"

config.movie_file_extension = ".mp4"
config.ffmpeg_quality = "20"
config.write_to_movie = True
config.use_opengl_renderer = False

class DijkstraVisualization(Scene):
    def construct(self):
        
# Data_S
# Data_E

        unique_edges = []
        seen_pairs = set()
        for n1, n2, w in edges:
            if (n2, n1) in seen_pairs or n1 == n2:
                continue
            seen_pairs.add((n1, n2))
            unique_edges.append((n1, n2, w))
        edges = unique_edges
        
        title = Text("Shortest Path Visualization", weight=BOLD).scale(0.6)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(0.5)

        header = ["Node", "Distance", "Previous"]
        table_data = [
            [n, str(distances[n]), previous[n] if previous[n] is not None else "Start"]
            for n in nodes
        ]

        table = Table(
            [header] + table_data,
            include_outer_lines=True,
            h_buff=0.7,
            v_buff=0.4,
        ).scale(0.4)
        table.to_corner(UL).shift(DOWN * 0.6 + RIGHT * 0.1)
        self.play(Write(table, shift=DOWN, scale=0.9), run_time=0.8)
        self.wait(0.3)

        header_row = table.get_rows()[0]
        self.play(header_row.animate.set_color(RED).scale(1.05), run_time=0.4)
        self.play(header_row.animate.set_color(WHITE).scale(1/1.05), run_time=0.4)
        self.wait(0.3)

        vertex_dots = {n: Dot(point=positions[n], color=WHITE) for n in nodes}
        vertex_labels = {n: Text(n, font_size=28) for n in nodes}

        graph_edges = []
        drawn_pairs = set()
        weights_texts = []
        for n1, n2, w in edges:
            if (n2, n1) in drawn_pairs:
                continue
            drawn_pairs.add((n1, n2))

            start = np.array(positions[n1], dtype=float)
            end = np.array(positions[n2], dtype=float)
            edge = Line(start, end, color=GRAY)

            weight = Text(str(w), font_size=24, color=RED)
            graph_edges.append(edge)
            weights_texts.append(weight)

        edges_group = VGroup(*graph_edges)
        dots_group = VGroup(*vertex_dots.values())

        labels_group = VGroup(*vertex_labels.values())
        weights_group = VGroup(*weights_texts)

        graph_group = VGroup(edges_group, dots_group, labels_group, weights_group)

        graph_frame = Rectangle(width=6.5, height=5.5, color=BLACK, stroke_opacity=0)
        graph_frame.next_to(table, RIGHT, buff=0.9)
        graph_frame.shift(DOWN * 2.2 + RIGHT * 0.5) 

        structural_target = VGroup(edges_group, dots_group)
        structural_target.scale_to_fit_height(graph_frame.height * 0.8)
        structural_target.scale_to_fit_width(graph_frame.width * 0.85)
        structural_target.move_to(graph_frame.get_center())

        transformed_positions = {n: vertex_dots[n].get_center() for n in nodes}

        for n in nodes:
            vertex_labels[n].move_to(transformed_positions[n] + np.array([0, 0.25, 0]))

        edge_index = 0
        for n1, n2, w in edges:
            start = transformed_positions[n1]
            end = transformed_positions[n2]
            mid = (start + end) / 2
            direction = end - start
            perp = np.array([-direction[1], direction[0], 0])
            if np.linalg.norm(perp) != 0:
                perp = perp / np.linalg.norm(perp)
            else:
                perp = np.array([0, 0.3, 0])

            weights_texts[edge_index].move_to(mid + 0.25 * perp)
            edge_index += 1

        final_graph_display = VGroup(edges_group, weights_group, dots_group, labels_group)
        final_graph_display.move_to(graph_frame.get_center())

        self.add(graph_frame)

        self.play(LaggedStart(*[Create(e) for e in graph_edges], lag_ratio=0.1))
        self.play(LaggedStart(*[Create(v) for v in vertex_dots.values()], lag_ratio=0.1))
        self.play(LaggedStart(*[Write(wt) for wt in weights_texts], lag_ratio=0.1))
        self.play(LaggedStart(*[Write(lab) for lab in vertex_labels.values()], lag_ratio=0.1))
        self.wait(0.8)

        transformed_positions = {n: vertex_dots[n].get_center() for n in nodes}
        path_edges = [
            Line(transformed_positions[shortest_path[i]],
                 transformed_positions[shortest_path[i + 1]],
                 color=RED, stroke_width=6)
            for i in range(len(shortest_path) - 1)
        ]

        self.play(table.animate.set_opacity(0.7))
        self.wait(0.3)

        for edge in path_edges:
            self.play(Create(edge), run_time=0.8)
            self.wait(0.2)

        for node in shortest_path:
            self.play(vertex_dots[node].animate.set_color(RED).scale(1.2), run_time=0.4)

        self.wait(1.2)

        fade_anims = [FadeOut(edge) for edge in path_edges]
        fade_anims += [vertex.animate.set_color(WHITE).scale(1 / 1.2) for vertex in vertex_dots.values()]
        self.play(*fade_anims, run_time=1.5)
        self.wait(0.5)

        self.play(FadeOut(VGroup(edges_group, weights_group, dots_group, labels_group)), 
                  FadeOut(table), FadeOut(title), FadeOut(graph_frame))
        self.wait()
