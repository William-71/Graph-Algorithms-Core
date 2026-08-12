
#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <vector>

class WeightedQuickUnion {
private:
    std::vector<int> parent;
    std::vector<int> size;
    int count; // 记录连通分量的数量

public:
    explicit WeightedQuickUnion(int n) : count(n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // 查找根节点 (带路径压缩 Path Compression)
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; // 压缩树高
            p = parent[p];
        }
        return p;
    }

    // 判断 p 和 q 是否连通
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // 合并 p 和 q 所在的集合 (按树大小加权)
    bool unionSets(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return false; // 已经在同一个集合中，若加入此边会形成环！

        // 小树挂在大树下
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
        return true;
    }

    int getCount() const {
        return count;
    }
};

#endif // DISJOINT_SET_HPP