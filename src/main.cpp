#include "graph.hpp"

#include <vector>

/*
       0 - 7
      / \ 
 4   1 - 2
  \ /
   3   5 - 6 
*/

int main() {
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

    return 0;
}