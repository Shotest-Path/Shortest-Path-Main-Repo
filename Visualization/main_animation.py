from manim import *
import numpy as np
class DijkstraVisualization(Scene):
    def construct(self):
        
# Data_S
# Data_E

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
        vertex_labels = {n: Text(n, font_size=28).next_to(vertex_dots[n], UP) for n in nodes}

        graph_edges = []
        drawn_pairs = set()
        for n1, n2, w in edges:
            if (n2, n1) in drawn_pairs:
                continue
            drawn_pairs.add((n1, n2))

            start = np.array(positions[n1], dtype=float)
            end = np.array(positions[n2], dtype=float)
            edge = Line(start, end, color=GRAY)

            direction = end - start
            perp = np.array([-direction[1], direction[0], 0], dtype=float)
            perp = perp / np.linalg.norm(perp) if np.linalg.norm(perp) != 0 else np.array([0, 0.3, 0])
            weight = Text(str(w), font_size=19, color=RED)
            weight.move_to(edge.get_center() + 0.25 * perp)
            graph_edges.append(VGroup(edge, weight))

        # Separate groups for scaling logic
        edges_group = VGroup(*[e[0] for e in graph_edges])  # only edge lines
        weights_group = VGroup(*[e[1] for e in graph_edges])  # weight labels
        dots_group = VGroup(*vertex_dots.values())
        labels_group = VGroup(*vertex_labels.values())

        # Scale only the structural parts (edges + dots)
        scale_target = VGroup(edges_group, dots_group)
        scale_target.scale_to_fit_height(config.frame_height * 0.6)
        scale_target.scale_to_fit_width(config.frame_width * 0.4)

        # After scaling, position everything together
        graph_group = VGroup(edges_group, weights_group, dots_group, labels_group)
        graph_group.next_to(table, RIGHT).shift(DOWN * 2).shift(LEFT * 1.3)

        # Now, reposition labels and weights so they stay near their scaled nodes/edges
        for n in nodes:
            vertex_labels[n].next_to(vertex_dots[n], UP)

        for (n1, n2, w), (_, weight) in zip(edges, graph_edges):
            start = vertex_dots[n1].get_center()
            end = vertex_dots[n2].get_center()
            direction = end - start
            perp = np.array([-direction[1], direction[0], 0])
            perp = perp / np.linalg.norm(perp) if np.linalg.norm(perp) != 0 else np.array([0, 0.3, 0])
            weight.move_to((start + end) / 2 + 0.25 * perp)


        self.play(LaggedStart(*[Create(e[0]) for e in graph_edges], lag_ratio=0.1))
        self.play(LaggedStart(*[Write(e[1]) for e in graph_edges], lag_ratio=0.1))
        self.play(LaggedStart(*[Create(v) for v in vertex_dots.values()], lag_ratio=0.1))
        self.play(LaggedStart(*[Write(l) for l in vertex_labels.values()], lag_ratio=0.1))
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

        self.play(FadeOut(graph_group), FadeOut(table), FadeOut(title))
        self.wait()
