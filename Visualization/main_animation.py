from manim import *

class DijkstraVisualization(Scene):
    def construct(self):
        
# Data_S
# Data_E

        title = Text("Shortest Path Visualization", weight=BOLD).scale(0.6)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(0.5)

        header = ["Node", "Distance", "Previous"]
        table_data = [[n, str(distances[n]), previous[n]] for n in nodes]

        table = Table(
            [header] + table_data,
            include_outer_lines=True,
            h_buff=0.7,
            v_buff=0.4,
        ).scale(0.55)


        table.to_corner(UL).shift(DOWN * 0.5 + RIGHT * 0.2)

        self.play(Create(table.get_horizontal_lines()))
        self.play(Create(table.get_vertical_lines()))
        self.wait(0.3)
        for i in range(len(nodes) + 1):
            self.play(FadeIn(table.get_rows()[i], shift=DOWN * 0.2), run_time=0.3)
        self.wait(0.5)

        offset = RIGHT * 3.5 + DOWN * 0.5
        vertex_dots = {n: Dot(point=positions[n], color=WHITE).shift(offset) for n in nodes}
        vertex_labels = {
            n: Text(n, font_size=28).next_to(vertex_dots[n], UP if n != "D" else DOWN)
            for n in nodes
        }

        graph_edges = []
        for n1, n2, w in edges:
            edge = Line(positions[n1] + offset, positions[n2] + offset, color=GRAY)
            weight = Text(str(w), font_size=24, color=YELLOW)
            weight.move_to(edge.get_center() + 0.3 * UP)
            graph_edges.append(VGroup(edge, weight))

        graph_group = VGroup(*vertex_dots.values(), *vertex_labels.values(), *graph_edges)

        self.play(LaggedStart(*[Create(e) for e in graph_edges], lag_ratio=0.1))
        self.play(LaggedStart(*[Create(v) for v in vertex_dots.values()], lag_ratio=0.1))
        self.play(LaggedStart(*[Write(l) for l in vertex_labels.values()], lag_ratio=0.1))
        self.wait(0.8)

        path_edges = []
        for i in range(len(shortest_path) - 1):
            n1, n2 = shortest_path[i], shortest_path[i + 1]
            edge = Line(
                positions[n1] + offset, positions[n2] + offset, color=RED, stroke_width=6
            )
            path_edges.append(edge)

        self.play(table.animate.set_opacity(0.7))
        self.wait(0.3)

        for edge in path_edges:
            self.play(Create(edge), run_time=0.8)
            self.wait(0.2)

        highlighted_nodes = []
        for node in shortest_path:
            anim = vertex_dots[node].animate.set_color(RED).scale(1.2)
            self.play(anim, run_time=0.4)
            highlighted_nodes.append(vertex_dots[node])

        self.wait(1.2)

        fade_anims = [FadeOut(edge) for edge in path_edges]
        fade_anims += [vertex.animate.set_color(WHITE).scale(1/1.2) for vertex in highlighted_nodes]
        self.play(*fade_anims, run_time=1.5)
        self.wait(0.5)

        self.play(FadeOut(graph_group), FadeOut(table), FadeOut(title))
        self.wait()
