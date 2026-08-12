#ifndef GRAPH_DFS_HPP
#define GRAPH_DFS_HPP

#include <vector>
#include <iostream>

class GraphDFS {
private:
    int V; // 顶点数
    std::vector<std::vector<int>> adj; // 邻接表

    // DFS 递归辅助函数：检测图中是否存在环
    bool hasCycleDFS(int v, std::vector<bool>& visited, int parent) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, visited, v)) {
                    return true;
                }
            }
            // 如果邻居已被访问，且不是当前节点的父节点，说明发现了环！
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

public:
    explicit GraphDFS(int vertices) : V(vertices), adj(vertices) {}

    // 添加无向边
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 检查整个图是否包含环
    bool containsCycle() {
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (hasCycleDFS(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif // GRAPH_DFS_HPP