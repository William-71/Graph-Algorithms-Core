#include <iostream>
#include "DisjointSet.hpp"
#include "GraphDFS.hpp"

// 函数前置声明：告诉 main 函数这两个测试在其他 .cpp 文件里
void testKruskal();
void testPrim();

int main() {
    // 1. DFS 环检测测试（保留你原本的代码）
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

    // 2. Weighted Quick Union 测试（保留你原本的代码）
    std::cout << "\n=== Testing Weighted Quick Union ===" << std::endl;
    WeightedQuickUnion wqu(5);
    wqu.unionSets(0, 1);
    wqu.unionSets(1, 2);

    std::cout << "0 and 2 connected? " << (wqu.connected(0, 2) ? "Yes" : "No") << std::endl;
    std::cout << "0 and 3 connected? " << (wqu.connected(0, 3) ? "Yes" : "No") << std::endl;

    // 3. 今日追加测试：Kruskal MST
    std::cout << "\n=== Testing Kruskal MST ===" << std::endl;
    testKruskal();

    // 4. 今日追加测试：Prim MST
    std::cout << "\n=== Testing Prim MST ===" << std::endl;
    testPrim();

    std::cout << "\n===================================" << std::endl;
    std::cout << "All tests executed successfully!" << std::endl;

    return 0;
}