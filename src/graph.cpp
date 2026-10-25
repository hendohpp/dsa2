#include "graph.hpp"

std::vector<std::vector<int>>
build_graph_vec(int n, const std::vector<std::vector<int>> &edges,
                bool directed) {
    std::vector<std::vector<int>> adj_list(n);

    for (const auto &edge : edges) {
        int v1 = edge[0];
        int v2 = edge[1];

        adj_list[v1].push_back(v2);
        if (!directed) {
            adj_list[v2].push_back(v1);
        }
    }

    return adj_list;
}

void bfs(std::vector<std::vector<int>>& graph, int src) {
    int N = graph.size();
    if (N == 0 || src >= N || src < 0) {
        std::cout << "Invalid input.\n";
        return;
    }

    std::cout << "Starting BFS on: " << src << "\n";

    // 
    std::vector<bool> visited(N, false);
    visited[src] = true;

    // 
    std::queue<int> vertex_queue;
    vertex_queue.push(src);

    while (!vertex_queue.empty()) {
        int curr_v = vertex_queue.front();
        vertex_queue.pop();

        std::cout << "Visited node: " << curr_v << "\n";

        for (int v : graph[curr_v]) {
            if (!visited[v]) {
                visited[v] = true;
                vertex_queue.push(v);
            }
        }
    }
}