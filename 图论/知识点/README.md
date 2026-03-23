# 图论 Graph Theory

## 基本概念

- **图（Graph）**：由顶点（Vertex）和边（Edge）组成
- **有向图 / 无向图**：边是否有方向
- **加权图**：边带有权重

## 树（Tree）

- 树是无环连通图，n 个顶点 n-1 条边
- **二叉树**：每个节点最多两个子节点
- **树的遍历**：前序、中序、后序、层序（BFS）

## 图的遍历

### 深度优先搜索（DFS）
```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
}
```

### 广度优先搜索（BFS）
```cpp
void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

## 最短路径

- **Dijkstra**：单源最短路，非负权重，O((V+E)logV)
- **Bellman-Ford**：单源最短路，允许负权重，O(VE)
- **Floyd-Warshall**：多源最短路，O(V³)

## 并查集（Union-Find）

用于判断连通性、检测环：
```cpp
int parent[MAXN];
int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
void unite(int x, int y) { parent[find(x)] = find(y); }
```
