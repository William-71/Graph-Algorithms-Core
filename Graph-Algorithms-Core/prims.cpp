#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> Pair; // <weight, vertex>

int primMST(int V, const std::vector<std::vector<Pair>>& adj) {
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    std::vector<bool> in_mst(V, false);
    int mst_weight = 0;
    int visited_count = 0;

    pq.push(Pair(0, 0)); // {weight, vertex}

    while (!pq.empty()) {
        Pair current = pq.top();
        pq.pop();

        int w = current.first;
        int u = current.second;

        if (in_mst[u]) continue;

        in_mst[u] = true;
        mst_weight += w;
        visited_count++;

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int weight = adj[u][i].first;
            int v = adj[u][i].second;
            if (!in_mst[v]) {
                pq.push(Pair(weight, v));
            }
        }
    }

    return (visited_count == V) ? mst_weight : -1;
}

// 供 main.cpp 调用的入口
void testPrim() {
    int V = 4;
    std::vector<std::vector<Pair>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back(Pair(w, v));
        adj[v].push_back(Pair(w, u));
        };

    addEdge(0, 1, 10);
    addEdge(0, 2, 6);
    addEdge(0, 3, 5);
    addEdge(1, 3, 15);
    addEdge(2, 3, 4);

    int result = primMST(V, adj);
    std::cout << "[Prim] MST Total Weight: " << result << std::endl;
}