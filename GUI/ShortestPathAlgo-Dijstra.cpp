#include <map>
#include <queue>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

inline void dijkstra(
    map<char, map<char, double>>& graph,
    char start,
    char end,
    map<char, double>& dist,
    map<char, char>& prev,
    vector<char>& shortest_path
    ) {
    map<char, bool> visited;
    for (auto& node : graph) {
        dist[node.first] = numeric_limits<double>::max();
        prev[node.first] = 0;
        visited[node.first] = false;
    }
    dist[start] = 0;

    priority_queue<pair<double, char>, vector<pair<double, char>>, greater<pair<double, char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        char current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (auto& neighbor : graph[current]) {
            char next = neighbor.first;
            double weight = neighbor.second;
            double newDist = dist[current] + weight;

            if (newDist < dist[next]) {
                dist[next] = newDist;
                prev[next] = current;
                pq.push({newDist, next});
            }
        }
    }


    stack<char> path;
    char node = end;
    while (node != 0) {
        path.push(node);
        node = prev[node];
        if (node == 0) break;
    }

    while (!path.empty()) {
        shortest_path.push_back(path.top());
        path.pop();
    }
}
