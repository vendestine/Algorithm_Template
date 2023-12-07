/*
模板题


=====================================================树的存储========================================================
dmy_527. 求树上路径(http://oj.daimayuan.top/course/7/problem/527)


有根树和无根树 基本一致；
两点区别  1. edges[x]存的点 2.father

- 存储方式
// 邻接矩阵  树是稀疏图，没有必要用邻接矩阵来存，用邻接表存即可

1. 出边数组 

vector<int> edges[N + 1];   //N-最多点数  有根树：edges[x] 点x的所有儿子的编号； 无根树：edges[x] 点x的所有相邻点的编号
int n, father[N + 1];       //n 点数  father针对有根树

void addEdge(int x, int y) {
    edges[x].push_back(y);
    father[y] = x  // 有根树
}

// 遍历x的所有儿子
for (auto y: edge[x]) {};



2. 邻接表

struct Node {
    int where;
    Node * next;
};

Node * head[N + 1], a[M]           // N最多点数 M最多边数
int n, father[N + 1], l = 0;       // father针对有根树

void addEdge (int x, int y) {
    a[++l].where = y;
    a[l].next = head[x];
    head[x] = &a[l];
    father[y] = x；                // 有根树
}

// 遍历x的所有儿子
for (Node * p = head[x]; p; p = p->next) {
    p->where
}



=====================================================树的遍历========================================================

----------------------------------------------有根树--------------------------------------------
点有父子关系，遍历儿子，不会重复

- DFS
void dfs(int x) {
    for x 的所有儿子 y {
        dfs(y);
    }
}
dfs(root);

- BFS
void bfs(int root) {
    root加入队列q;
    while (q not empty) {
        x = 队首，x出队；
        for x 的所有儿子 y {
            y入队；
        }
    }
}
bfs(root)


----------------------------------------------无根树--------------------------------------------
dmy_527. 求树上路径(http://oj.daimayuan.top/course/7/problem/527)

点没有父子关系，只有相邻关系，遍历相邻点，会重复；用pre记录from，防止重复
选择任意一点为根节点，进行遍历即可

- DFS
void dfs(int x) {
    for x 的所有相邻点 y {
        if (y != pre[x]) 
            pre[y] = x;
            dfs(y);
    }
}
dfs(x);

- BFS
void bfs(int x) {
    x加入队列q；
    while (q not empty) {
        x = 队首，x出队；
        for x 的所有相邻点 y {
            if (y != pre[x]) 
                pre[y] = x;
                y入队;
        }
    }
}
bfs(x);

*/


// 无根树求 两点路径 DFS
class dmy_527_01 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 100000;

    int n, pre[N + 1], a[N + 1];
    vector<int> edges[N + 1];

    void dfs(int x) {
        for (auto y: edges[x]) {
            if (y != pre[x]) {
                pre[y] = x;
                dfs(y);
            }
        }
    }

    int main() {
        cin >> n;
        for (int i = 1; i < n; i ++) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        int u, v;
        cin >> u >> v;
        
        pre[u] = -1;
        dfs(u);

        int l = 0;
        for (int i = v; i != u; i = pre[i]) a[++l] = i;
        a[++l] = u;

        for (int i = l; i; i --) cout << a[i] << " ";
    }
};


// 无根树求 两点路径 BFS
class dmy_527_02 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 100000;

    int n, pre[N + 1], a[N + 1], q[N + 1], front = 1, rear = 0;
    vector<int> edges[N + 1];

    void bfs(int x) {
        q[++rear] = x;
        while (front <= rear) {
            int x = q[front];
            front++;
            for (auto y: edges[x]) {
                if (y != pre[x]) {
                    pre[y] = x;
                    q[++rear] = y;
                }
            }
        }
    }

    int main() {
        cin >> n;
        for (int i = 1; i < n; i ++) {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        
        int u, v;
        cin >> u >> v;
        
        pre[u] = -1;
        bfs(u);

        int l = 0;
        for (int i = v; i != u; i = pre[i]) a[++l] = i;
        a[++l] = u;

        for (int i = l; i; i --) cout << a[i] << " ";
    }
};

