#ifndef GRAPH_GEOMETRY_H
#define GRAPH_GEOMETRY_H
#include <map>
#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <array>
class GraphGeometry {
public:
    // Returns true if distance found between two nodes
    static bool getDistanceBetweenNodes(
        const std::map<char, std::map<char, double>>& graph,
        char firstNode,
        char secondNode,
        double& distanceOut
        ) {
        auto fromFirst = graph.find(firstNode);
        if (fromFirst != graph.end()) {
            auto toSecond = fromFirst->second.find(secondNode);
            if (toSecond != fromFirst->second.end()) {
                distanceOut = toSecond->second;
                return true;
            }
        }

        auto fromSecond = graph.find(secondNode);
        if (fromSecond != graph.end()) {
            auto toFirst = fromSecond->second.find(firstNode);
            if (toFirst != fromSecond->second.end()) {
                distanceOut = toFirst->second;
                return true;
            }
        }

        return false;
    }

    static std::map<char, std::array<double, 3>> generateNodePositions(
        const std::map<char, std::map<char, double>>& graph
        ) {
        std::map<char, std::array<double, 3>> points;
        if (graph.empty()) return points;

        int n = graph.size();
        double radius = 10.0;
        double angleStep = 2.0 * M_PI / n;

        int i = 0;
        for (auto& [node, _] : graph) {
            double angle = i * angleStep;
            double x = radius * cos(angle);
            double y = radius * sin(angle);
            points[node] = {x, y, 0.0};
            i++;
        }
        return points;
    }
};

#endif // GRAPH_GEOMETRY_H
