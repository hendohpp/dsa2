#include "graph.hpp"

#include <vector>

int main() {
    // example 1: 2D matrix graph representation
    /*
              0 - 7
             / \
        4   1 - 2
         \ /
          3   5 - 6
    */
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 7}, {1, 2},
                                           {1, 3}, {4, 3}, {5, 6}};

    std::vector<std::vector<int>> g = build_graph_vec(8, edges, false);

    // explores the large graph
    bfs(g, 0);

    // explores the 5-6 subgraph
    bfs(g, 5);

    // throw error
    std::vector<std::vector<int>> empty;
    bfs(empty, 0);
    bfs(g, 100);

    // example 2: hash map of strings representation
    /*
        hello - world - two
             \ /
              i   love - c++
               \
                matlab
    */
    std::vector<std::vector<std::string>> edges2 = {
        {"hello", "world"}, {"hello", "i"},  {"world", "i"},
        {"world", "two"},   {"love", "c++"}, {"i", "matlab"}};

    std::vector<std::string> vertices = {"hello", "world", "two", "i", "love", "c++", "matlab"};

    std::unordered_map<std::string, std::vector<std::string>> g2 =
        build_graph_umap(vertices, edges2, false);

    // throw error
    std::unordered_map<std::string, std::vector<std::string>> empty2;
    bfs<std::string>(empty2, "");

    // traverse large part of graph
    bfs<std::string>(g2, "hello");

    // traverse small part
    bfs<std::string>(g2, "c++");

    return 0;
}