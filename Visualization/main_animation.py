from manim import *
import numpy as np

# Data_S
# Data_E

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
                Tex(str(w), font_size=24, color="#FAF0D9"),
                radius=0.16,
                color="#830467"
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

        self.play(FadeOut(title, shift=UP), run_time=0.9)
        self.wait(0.2)

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

        grid_lines = VGroup(*table.get_horizontal_lines(), *table.get_vertical_lines())
        self.play(LaggedStartMap(Create, grid_lines, lag_ratio=0.15), run_time=1.6)
        self.play(LaggedStartMap(DrawBorderThenFill, table.get_rows(), lag_ratio=0.18), run_time=1.8)
        self.wait(1.0)

        self.fit_camera_to_mobjects(points, scale=1.35, run_time=1.1)
        self.wait(0.35)

        G.build_edges()
        nodes_group, lines_group, weights_group, lines = G.items_all()
        self.play(LaggedStartMap(DrawBorderThenFill, points, lag_ratio=0.25), run_time=1.5)
        self.wait(0.2)
        self.play(LaggedStartMap(Create, lines_group, lag_ratio=0.18), run_time=2.0)
        self.play(LaggedStartMap(DrawBorderThenFill, weights_group, lag_ratio=0.2), run_time=1.4)
        self.wait(0.3)

        for i in range(len(shortest_path) - 1):
            a, b = shortest_path[i], shortest_path[i + 1]
            if (a, b) in lines:
                self.play(lines[(a, b)].animate.set_color(RED).set_stroke_width(8), run_time=1.0)
                self.wait(0.25)

        self.wait(0.8)

        final_group = VGroup(nodes_group, lines_group, weights_group, table)
        self.fit_camera_to_mobjects(final_group, scale=3, run_time=1.6)
        self.wait(2.5)

    def _mobject_representative_points(self, mob):
        if isinstance(mob, Line):
            return [mob.get_start(), mob.get_end()]
        try:
            ul = mob.get_corner(UL)
            dr = mob.get_corner(DR)
            return [ul, dr]
        except Exception:
            return [mob.get_center()]

    def _collect_points_from_mobjects(self, mobjects):
        mob_list = mobjects.submobjects if isinstance(mobjects, VGroup) else [mobjects]
        pts = []
        for mob in mob_list:
            pts.extend(self._mobject_representative_points(mob))
        pts = np.array(pts)
        if pts.size == 0:
            return np.array([[0.0, 0.0, 0.0]])
        return pts

    def fit_camera_to_mobjects(self, mobjects, scale=1.2, run_time=1.2):
        pts = self._collect_points_from_mobjects(mobjects)
        x_min, y_min = np.min(pts[:, 0]), np.min(pts[:, 1])
        x_max, y_max = np.max(pts[:, 0]), np.max(pts[:, 1])
        width = max(0.5, (x_max - x_min))
        height = max(0.5, (y_max - y_min))
        margin_x = width * (scale - 1.0) + 0.5
        margin_y = height * (scale - 1.0) + 0.5
        target_center = np.array([(x_max + x_min) / 2, (y_max + y_min) / 2, 0])
        target_width = width + margin_x
        target_height = height + margin_y
        self.play(
            self.camera.frame.animate.move_to(target_center).set(
                width=target_width, height=target_height
            ),
            run_time=run_time,
            rate_func=smooth
        )
