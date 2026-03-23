# 搜索与回溯 Search & Backtracking

## 回溯算法框架

回溯是一种通过穷举所有可能来求解问题的算法，核心是"做选择 → 递归 → 撤销选择"。

```python
def backtrack(path, choices):
    if 满足终止条件:
        result.append(path[:])
        return
    for choice in choices:
        # 做选择
        path.append(choice)
        # 递归
        backtrack(path, 新的choices)
        # 撤销选择
        path.pop()
```

## 剪枝

- **有效剪枝**：在搜索过程中提前终止不可能产生解的分支
- 排序后可以更早判断是否需要剪枝

## 全排列

n 个不重复元素的全排列共有 n! 种：
```python
def permute(nums):
    result = []
    def backtrack(path, used):
        if len(path) == len(nums):
            result.append(path[:])
            return
        for i in range(len(nums)):
            if not used[i]:
                used[i] = True
                path.append(nums[i])
                backtrack(path, used)
                path.pop()
                used[i] = False
    backtrack([], [False] * len(nums))
    return result
```

## 组合问题

在 n 个元素中选 k 个的组合：
```python
def combine(n, k):
    result = []
    def backtrack(start, path):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()
    backtrack(1, [])
    return result
```

## N 皇后

在 n×n 棋盘上放 n 个皇后，使得互不攻击：
- 每行、每列、每条对角线上只能有一个皇后
- 可以用三个集合记录已占用的列、正对角线、反对角线

## DFS vs BFS

| | DFS | BFS |
|--|-----|-----|
| 数据结构 | 栈（递归） | 队列 |
| 空间复杂度 | O(深度) | O(宽度) |
| 适用 | 找所有解、连通性 | 最短路径（无权图） |
