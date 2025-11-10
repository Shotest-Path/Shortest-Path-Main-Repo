from manim import *
import numpy as np

# Data_S
nodes = ["A","B","C","D",]
edges = [
        ("A","B",5.65685),
        ("A","C",3.16228),
        ("A","D",4),
        ("B","A",5.65685),
        ("B","C",3.16228),
        ("C","A",3.16228),
        ("C","B",3.16228),
        ("C","D",1.41421),
        ("D","A",4),
        ("D","C",1.41421),
        ]
distances = {"A":0,"B":5.65685,"C":3.16228,"D":4,}
previous = {"A":None,"B":"A","C":"A","D":"A",}
shortest_path = ["A","B",]
predefined_coordinates={
        "A":np.array([0, 0, 0]),
        "B":np.array([4, 4, 0]),
        "C":np.array([3, 1, 0]),
        "D":np.array([4, 0, 0]),
        }

# Data_E

num_nodes = len(nodes)
radius = 4.0
angles = np.linspace(0, 2 * np.pi, num_nodes, endpoint=False)
coordinates = {nodes[i]: np.array([radius * np.cos(angles[i]), radius * np.sin(angles[i]), 0]) for i in range(num_nodes)}
class Point:

    def __init__(self, pos, node, radius=0.25):
        self.node = node
        self.radius = radius
        self.dot = LabeledDot(
            MathTex(str(node), font_size=36, color=BLACK),
            radius=radius,
            color=WHITE
        )
        self.dot.move_to(pos)


class DijkstraGraph:
   
    def __init__(self, nodes, edges, coordinates):
        self.nodes = nodes
        self.coordinates = coordinates

        unique_edges = []
        seen_pairs = set()
        for n1, n2, w in edges:
            if (n2, n1) in seen_pairs or n1 == n2:
                continue
            seen_pairs.add((n1, n2))
            unique_edges.append((n1, n2, w))
        self.edges = unique_edges

        self.points = {}
        for node in nodes:
            point = Point(coordinates[node], node)
            self.points[node] = point.dot

        self.lines = {}
        self.lines_group = VGroup()
        self.weights_group = VGroup()

    def build_edges(self):
        self.lines_group = VGroup()
        self.weights_group = VGroup()
        self.lines = {}

        for a, b, w in self.edges:
            start = self.points[a].get_center()
            end = self.points[b].get_center()
            dir_vec = end - start
            unit = dir_vec / np.linalg.norm(dir_vec)
            start_trim = start + unit * self.points[a].radius
            end_trim = end - unit * self.points[b].radius

            line = Line(start_trim, end_trim, stroke_width=5, color=BLUE)
            self.lines[(a, b)] = line
            self.lines[(b, a)] = line
            self.lines_group.add(line)

            mid = (start_trim + end_trim) / 2
            weight_label = LabeledDot(
                Tex(str(w), font_size=24, color="#000000"),
                radius=0.2,
                color="#FFFFFF"
            ).move_to(mid)
            self.weights_group.add(weight_label)

    def items_nodes_only(self):
        return VGroup(*self.points.values())

    def items_all(self):
        return VGroup(*self.points.values()), self.lines_group, self.weights_group, self.lines


class DynamicGraphScene(MovingCameraScene):
    def construct(self):

        title = Text("Shortest Path Visualization", weight=BOLD).scale(0.6)
        title.to_edge(UP)
        self.play(Create(title, shift=UP), run_time=1)
        self.wait(0.4)

        self.play(FadeOut(title, shift=UP), run_time=1)
        self.wait(0.3)

        G = DijkstraGraph(nodes, edges, coordinates)
        points = G.items_nodes_only()

        header = ["Node", "Distance", "Previous"]
        table_data = [
            [str(n), str(distances[n]), str(previous[n]) if previous[n] else "-"]
            for n in nodes
        ]

        table = Table(
            table_data,
            col_labels=[Text(h) for h in header],
            include_outer_lines=True,
            h_buff=1.2,
            v_buff=0.4
        ).scale(0.4)

        table.to_corner(UP + LEFT)
        table.shift(DOWN * 0.8)
        
        points.next_to(table, RIGHT, buff=5)

        self.camera.frame.move_to(VGroup(table, points).get_center()).set_width(VGroup(table, points).get_width() * 1.2)

        grid_lines = VGroup(*table.get_horizontal_lines(), *table.get_vertical_lines())
        self.play(LaggedStartMap(Create, grid_lines, lag_ratio=0.15), run_time=1.6)
        self.play(LaggedStartMap(DrawBorderThenFill, table.get_rows(), lag_ratio=0.18), run_time=1.8)
        self.wait(1.0)

        # Zoom in on graph
        self.play(self.camera.frame.animate.move_to(points.get_center()).set_width(points.get_width() * 2))

        G.build_edges()
        nodes_group, lines_group, weights_group, lines = G.items_all()
        self.play(LaggedStartMap(DrawBorderThenFill, points, lag_ratio=0.25), run_time=1.5)
        self.wait(0.2)
        self.play(LaggedStartMap(Create, lines_group, lag_ratio=0.18), run_time=2.0)
        self.play(LaggedStartMap(DrawBorderThenFill, weights_group, lag_ratio=0.2), run_time=1.4)
        self.wait(0.3)

        self.add_foreground_mobject(weights_group)

        for i in range(len(shortest_path) - 1):
            a, b = shortest_path[i], shortest_path[i + 1]
            if (a, b) in lines:
                original_line = lines[(a, b)]
                red_line = Line(
                    original_line.get_start(),
                    original_line.get_end(),
                    stroke_width=8,
                    color=RED
                )
                self.play(Create(red_line), run_time=1.0)
                self.wait(0.25)

        self.wait(0.8)

        self.wait(2.5)
