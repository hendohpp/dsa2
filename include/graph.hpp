#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// --- graph representations --- //

// this version implicitly handles recording all vertices by taking in n as # vertices (0 to n - 1)
std::vector<std::vector<int>>
build_graph_vec(int n, const std::vector<std::vector<int>> &edges,
                bool directed = false);

template <typename T>
std::unordered_map<T, std::vector<T>>
build_graph_umap(const std::vector<T> &vertices,
                 const std::vector<std::vector<T>> &edges,
                 bool directed = false) {
    std::unordered_map<T, std::vector<T>> adj_list;

    // account for nodes that do not have any neighbors
    for (const auto &vert : vertices) {
        adj_list[vert] = {};   
    }

    for (const auto &edge : edges) {
        T v1 = edge[0];
        T v2 = edge[1];

        adj_list[v1].push_back(v2);
        if (!directed) {
            adj_list[v2].push_back(v1);
        }
    }

    return adj_list;
}

// --- implementations --- //

void bfs(std::vector<std::vector<int>> &graph, int src);
void dfs(std::vector<std::vector<int>> &graph, int src);

template <typename T>
void bfs(std::unordered_map<T, std::vector<T>> &graph, T src) {
    int N = graph.size();
    if (N == 0 || !graph.contains(src)) {
        std::cout << "Invalid input.\n";
        return;
    }

    std::cout << "Starting BFS on: " << src << "\n";

    std::unordered_set<T> visited;
    std::queue<T> vertex_queue;

    visited.insert(src);
    vertex_queue.push(src);

    while (!vertex_queue.empty()) {
        T curr_v = vertex_queue.front();
        vertex_queue.pop();

        std::cout << "Visited: " << curr_v << "\n";

        for (T v : graph[curr_v]) {
            if (!visited.contains(v)) {
                visited.insert(v);
                vertex_queue.push(v);
            }
        }
    }
}

template <typename T>
void dfs_rec(std::unordered_map<T, std::vector<T>> &graph,
             std::unordered_set<T> &visited, T node) {
    if (visited.contains(node)) {
        return;
    }

    std::cout << "Visited: " << node << "\n";
    visited.insert(node);

    for (T v : graph[node]) {
        dfs_rec(graph, visited, v);
    }
}

template <typename T>
void dfs(std::unordered_map<T, std::vector<T>> &graph, T src) {
    int N = graph.size();
    if (N == 0 || !graph.contains(src)) {
        std::cout << "Invalid input.\n";
        return;
    }

    std::cout << "Starting DFS on: " << src << "\n";

    std::unordered_set<T> visited;
    dfs_rec(graph, visited, src);
}

#endif // GRAPH_HPP_