#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class DSU_Kruskal {
private:
    std::vector<int> parent;
public:
    explicit DSU_Kruskal(int n) : parent(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int kruskalMST(int V, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    DSU_Kruskal dsu(V);
    int mst_weight = 0;
    int edges_count = 0;

    for (size_t i = 0; i < edges.size(); ++i) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            mst_weight += edges[i].w;
            edges_count++;
            if (edges_count == V - 1) break;
        }
    }
    return (edges_count == V - 1) ? mst_weight : -1;
}

// 供 main.cpp 调用的入口
void testKruskal() {
    int V = 4;
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int result = kruskalMST(V, edges);
    std::cout << "[Kruskal] MST Total Weight: " << result << std::endl;
}   