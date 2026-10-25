#include "graph.hpp"

int main() {
    // example 1: 2D matrix
    /*
         0 - 1 - 2
        / \      |
       5   4     3

       6 - 7
    */
    std::vector<std::vector<int>> edges1 = {{0, 1}, {0, 5}, {0, 4},
                                            {1, 2}, {2, 3}, {6, 7}};

    std::vector<std::vector<int>> graph1 = build_graph_vec(8, edges1, false);

    // should print 0 1 2 3, 5, 4
    dfs(graph1, 0);

    // should print 6 7
    dfs(graph1, 6);

    // should report error
    std::vector<std::vector<int>> empty1 = {};
    dfs(empty1, 0);
    dfs(graph1, 8);

    // example 2: generic type
    /*
        "hello"

        "world" - "I" - "am"
                   |       \
                "having"  "fun"
    */
    std::vector<std::vector<std::string>> edges2 = {
        {"world", "I"}, {"I", "am"}, {"I", "having"}, {"am", "fun"}};

    std::vector<std::string> vertices = {"hello", "world", "I", "am", "having", "fun"};

    std::unordered_map<std::string, std::vector<std::string>> graph2 = build_graph_umap(vertices, edges2);

    // world I am fun having
    dfs<std::string>(graph2, "world");

    // invalid input
    dfs<std::string>(graph2, "");

    dfs<std::string>(graph2, "hello");

    return 0;
}