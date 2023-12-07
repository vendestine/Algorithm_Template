# 算法模板库

## 使用说明

[表格题单](https://docs.google.com/spreadsheets/d/1-8uiWZgGRc4NgLgGnXCCuTpaJyqXYh5K7YWHCNxqJkg/edit#gid=635571784)里面会给出每个数据结构和算法的基本知识，题单，每道题的思路

[算法目录](#算法目录)里会以文件形式，列出每种算法的常用模板，表格题单每道题目的代码

## 目录文件结构
```
│  LICENSE
│  README.md
│  
├─basis # 基础算法
│  ├─binary_search #二分
│  │      binary_search_ans.cpp
│  │      binary_search_float.cpp
│  │      binary_search_int.cpp
│  │      ternary_search.cpp
│  │      
│  ├─bit_operation # 位运算
│  │      bits.cpp
│  │      set.cpp
│  │      
│  ├─pre_suf_diff # 前后缀，差分
│  │      diff.cpp
│  │      prefix_suffix_division.cpp
│  │      prefix_sum.cpp
│  │      
│  └─two_pointer # 双指针
│          opposite_direction.cpp
│          same_direction.cpp
│          sliding_window.cpp
│          
├─contest # 竞赛
│  ├─job_exam
│  ├─leetcode
│  │  └─371
│  │          A.cpp
│  │          B.cpp
│  │          
│  └─nowcoder
├─data_structure # 数据结构
│  └─stack
│          stack.cpp
│          
└─search # 搜索算法
        backtracking.cpp
        bfs.cpp
        dfs.cpp
```

## 算法目录

- 基础算法
    - 双指针 (同向 = 滑动窗口)
        - [不定长同向双指针](./basis/two_pointer/same_direction.cpp)
        - [定长同向双指针](./basis/two_pointer/sliding_window.cpp)
        - [相向双指针](./basis/two_pointer/opposite_direction.cpp)
    - 前缀和，后缀和，差分
        - [前后缀分解](./basis/pre_suf_diff/prefix_suffix_division.cpp)
        - [前缀和](./basis/pre_suf_diff/prefix_sum.cpp)
        - [差分](./basis/pre_suf_diff/diff.cpp)
    - 二分，三分
        - [整数二分](./basis/binary_search/binary_search_int.cpp)
        - [实数二分](./basis/binary_search/binary_search_float.cpp)
        - [二分答案](./basis/binary_search/binary_search_ans.cpp)
        - [三分](./basis/binary_search/ternary_search.cpp)
    - 位运算
        - [常用技巧](./basis/bit_operation/bits.cpp)
        - [集合论](./basis/bit_operation/set.cpp)
- 搜索
    - [DFS 深度优先搜索](./search/dfs.cpp)
    - [BFS 广度优先搜索](./search/bfs.cpp)
    - [回溯 DFS树形状态空间](./search/backtracking.cpp)

- 数据结构
    - [栈](./data_structure/stack/stack.cpp)
    - [队列](./data_structure/queue/queue.cpp)
    - [链表](./data_structure/List/list.cpp)
    - [二叉树](./data_structure/binary_tree/binary_tree.cpp)
    - 哈希表
    - 堆
    - 单调栈 
    - 单调队列
    - [树](./data_structure/tree/tree.cpp)
    - 字典树 Trie
    - 并查集

- 动态规划
    - 背包dp
        - 01背包
        - 完全背包
        - 多重背包
        - 分组背包
    - 线性dp
        - triangle 数字三角形模型
        - LIS 最长上升子序列模型
        - LCS 最长公共子序列模型
    - 区间dp
    - 数位dp
    - 状压dp
    - 树形dp
- 图论
    - 图的存储
    - 图的遍历
    - 最短路
        - Dijkstra
        - bellman-ford
        - SPFA
        - Floyd
    - 最小生成树
        - Prim
        - Kruskal
    - 二分图
    - 拓扑排序
- 数学
- 其他

## 学习资源
[灵神算法模板](https://github.com/EndlessCheng/codeforces-go/tree/master)

[leetcode3000+选手算法模板库](https://github.com/liupengsay/PyIsTheBestLang)

[acwing体系算法模板库](https://github.com/upupming/algorithm/tree/master)


