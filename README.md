# Graph Algorithms Core in C++

一个基于 C++17 实现的模块化图论算法与数据结构核心库。本项目包含了标准图算法的实现、复杂度分析以及自动化回归测试用例。

---

## 🛠️ 包含算法与数据结构列表

| 类别 | 算法 / 数据结构 | 源文件 | 时间复杂度 | 空间复杂度 | 测试状态 |
| :--- | :--- | :--- | :--- | :--- | :---: |
| **连通性** | 并查集 (Weighted Quick Union) | `DisjointSet.hpp` | $O(\alpha(N))$ | $O(N)$ |  Passed |
| **图遍历** | DFS 深度优先搜索（含环检测） | `GraphDFS.hpp` | $O(V + E)$ | $O(V)$ |  Passed |
| **最小生成树** | Kruskal 算法（加边法） | `kruskal.cpp` | $O(E \log E)$ | $O(V + E)$ |  Passed |
| **最小生成树** | Prim 算法（加点法 + 优先队列）| `prims.cpp` | $O(E \log V)$ | $O(V + E)$ |  Passed |

---

## 💻 开发与环境要求

* **编程语言**：C++17 及以上
* **开发环境**：Microsoft Visual Studio 2022
* **构建工具**：MSVC Compiler / MSBuild

---

## 🚀 本地运行与测试说明

1. 使用 Visual Studio 打开 `Graph-Algorithms-Core.sln` 解决方案。
2. 确保项目属性中的 **C++ 语言标准** 已设置为 **ISO C++17 (`/std:c++17`)** 或更高版本。
3. 按下快捷键 `Ctrl + F5` 编译并运行 `main.cpp`。
4. 控制台将自动执行并打印各模块的单测验证结果。