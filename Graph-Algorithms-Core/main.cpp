#include <iostream>
#include "DisjointSet.hpp"
#include "GraphDFS.hpp"

int main() {
    std::cout << "=== Testing DFS Cycle Detection ===" << std::endl;
    GraphDFS graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0); // 形成三角形环 0-1-2-0

    if (graph.containsCycle()) {
        std::cout << "[DFS] Graph contains a cycle!" << std::endl;
    }
    else {
        std::cout << "[DFS] Graph is a tree / acyclic." << std::endl;
    }

    std::cout << "\n=== Testing Weighted Quick Union ===" << std::endl;
    WeightedQuickUnion wqu(5);
    wqu.unionSets(0, 1);
    wqu.unionSets(1, 2);

    std::cout << "0 and 2 connected? " << (wqu.connected(0, 2) ? "Yes" : "No") << std::endl;
    std::cout << "0 and 3 connected? " << (wqu.connected(0, 3) ? "Yes" : "No") << std::endl;

    return 0;
}