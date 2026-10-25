#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// --- graph representations --- //

/**
 * @brief creates a graph in a 2D matrix adj list representation,
 * best for dense graphs
 *
 * @param n number of vertices in the graph
 * @param edges a list of pairs <v1, v2> representing an edge from v1 to v2
 * @param directed whether the edges are directed or undirected
 * @return adjacency list
 */
std::vector<std::vector<int>>
build_graph_vec(int n, const std::vector<std::vector<int>> &edges,
                bool directed = false);

/**
 * @brief creates a graph in a hash map adj list representation,
 * best for sparse graphs
 *
 * @param edges a list of pairs <v1, v2> representing and edge from v1 to v2
 * @param directed whether the edges are directed or undirected
 * @return adjacency list
 */
template <typename T>
std::unordered_map<T, std::vector<T>>
build_graph_umap(const std::vector<std::vector<T>> &edges,
                 bool directed = false) {
    std::unordered_map<T, std::vector<T>> adj_list;

    for (const auto& edge : edges) {
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

void bfs(std::vector<std::vector<int>>& graph, int start_v);

template <typename T>
void bfs(std::unordered_map<T, std::vector<T>>& graph);

#endif // GRAPH_HPP_