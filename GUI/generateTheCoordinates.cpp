#include <iostream>
#include <map>
#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
bool getDistanceBetweenNodes(
    const map<char, map<char, double>>& graph,
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

map<char, array<double, 3>> generateNodePositions(
    const map<char, map<char, double>>& graph
    ) {
    map<char, array<double, 3>> positions;
    if (graph.empty()) return positions;

    srand(static_cast<unsigned>(time(nullptr)));

    // Step 1: choose first node (A)
    char first = graph.begin()->first;
    positions[first] = {0.0, 0.0, 0.0};

    // Step 2: find a neighbor (B)
    char second = 0;
    double dAB = 0.0;
    for (auto& [neighbor, dist] : graph.at(first)) {
        second = neighbor;
        dAB = dist;
        break;
    }

    if (second == 0) {
        cerr << "Warning: graph too small.\n";
        return positions;
    }

    positions[second] = {dAB, 0.0, 0.0};

    // Step 3: place the rest of the nodes
    for (auto& [node, edges] : graph) {
        if (positions.count(node)) continue; // already placed

        double dToA, dToB;
        bool hasA = getDistanceBetweenNodes(graph, node, first, dToA);
        bool hasB = getDistanceBetweenNodes(graph, node, second, dToB);

        double x, y;

        if (hasA && hasB) {
            // Check if geometry possible
            if (dToA + dToB > dAB && fabs(dToA - dToB) < dAB) {
                // Law of cosines
                x = (pow(dToA, 2) - pow(dToB, 2) + pow(dAB, 2)) / (2 * dAB);
                double ySquared = pow(dToA, 2) - pow(x, 2);
                y = (ySquared > 0) ? sqrt(ySquared) : 0.0;
            } else {
                // Impossible triangle → approximate placement
                x = (double)(rand() % 20) - 10.0;
                y = (double)(rand() % 20) - 10.0;
            }
        } else {
            // Missing distances → approximate placement
            x = (double)(rand() % 20) - 10.0;
            y = (double)(rand() % 20) - 10.0;
        }

        positions[node] = {x, y, 0.0};
    }

    return positions;
}
