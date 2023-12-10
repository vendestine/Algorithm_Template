/*
模板题


=======================================================图上BFS========================================================
dmy_630. 求距离(http://oj.daimayuan.top/course/14/problem/630)
dmy_631. 迷宫(http://oj.daimayuan.top/course/14/problem/631)



- 普通BFS
int n, m, dist[N + 1], q[N + 1];          //n点数，m边数，N最多点数, dist距离数组
vector<int> edge[N + 1];                  //邻接表存图

void bfs(int s) {
    memset(dist, 255, sizeof(dist));      // 初始化所有点与起点距离-1；
    dist[s] = 0;                          // 起点距离为0
    int front = 1, rear = 0;
    q[++rear] = s;
    while (front <= rear) {
        int x = q[front];
        ++front;
        for (auto y: edge[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q[++rear] = y;
            }
        }
    }
}


- 网格图BFS
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};      // {行号移动量，列号移动量}
int n, m, dist[N + 1][M + 1], q[N * M + 1][2];         // n行 m列 N最多行 M最多列 N*M最多格子（点）
char s[N + 1][M + 2];                                  // 二维矩阵存网格图

void bfs(int sx, int sy) {
    memset(dist, 255, sizeof(dist));
    dist[sx][sy] = 0;
    int front = 1, rear = 0;
    q[++rear][0] = sx; q[rear][1] = sy;
    while (front <= rear) {
        int x = q[front][0], y = q[front][1];
        ++front;
        for (int i = 0; i < 4; i ++) {
            int xx = x + d[i][0], yy = y + d[i][1];
            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;
            if (s[xx][yy] != 'X' && dist[xx][yy] == -1) {
                dist[xx][yy] = dist[x][y] + 1;
                q[++rear][0] = xx, q[rear][1] = yy;
            }
        }
    } 
}





=======================================================图上DFS========================================================
dmy_629. 连通块计数(http://oj.daimayuan.top/course/14/problem/629)


- 普通DFS
int n, m;
bool vis[N + 1];
vector<int> edge[N + 1];

void dfs(int x) {
    vis[x] = true;
    for (auto y: edge[x]) {
        if (!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    memset(vis, false, sizeof(vis));
    dfs(s);
}

*/



// BFS求两点距离
class dmy_630 {
    #include <bits/stdc++.h>

    using namespace std;
    const int N = 20000, M = 100000;

    int n, m, k, q[N + 1], dist[N + 1];
    vector<int> edge[N + 1];


    int main() {
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i ++) {
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        while (k --) {
            int s, e;
            cin >> s >> e;
            // BFS
            memset(dist, 255, sizeof(dist));
            dist[s] = 0;                        
            int front = 1, rear = 0;
            q[++rear] = s;
            while (front <= rear) {
                int x = q[front];
                ++front;
                for (auto y: edge[x]) {
                    if (dist[y] == -1) {
                        dist[y] = dist[x] + 1;
                        q[++rear] = y;
                    }
                }
            }
            cout << dist[e] << endl;
        }
        return 0;
    }
};


// 网格BFS求最短路
class dmy_631 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1000, M = 1000;

    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    int n, m, q[N * M + 1][2], dist[N + 1][M + 1];
    char s[N + 1][M + 2];

    int main() {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                cin >> s[i][j];

        int sx, sy, ex, ey;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (s[i][j] == 'S') sx = i, sy = j;
                if (s[i][j] == 'E') ex = i, ey = j;
            }
        }
        // 网格图BFS
        memset(dist, 255, sizeof(dist));
        dist[sx][sy] = 0;
        int front = 1, rear = 0;
        q[++rear][0] = sx; q[rear][1] = sy;
        while (front <= rear) {
            int x = q[front][0], y = q[front][1];
            ++front;
            for (int i = 0; i < 4; i ++) {
                int xx = x + d[i][0], yy = y + d[i][1];
                if (xx < 1 || xx > n || yy < 1 || yy > m)
                    continue;
                if (s[xx][yy] != 'X' && dist[xx][yy] == -1) {
                    dist[xx][yy] = dist[x][y] + 1;
                    q[++rear][0] = xx, q[rear][1] = yy;
                }
            }
        } 
        cout << dist[ex][ey] << endl;
        return 0;
    }
};



// DFS统计连通块数量
class dmy_629 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 20000, M = 100000;

    int n, m;
    vector<int> edge[N + 1];
    bool vis[N + 1];

    void dfs(int x) {
        vis[x] = true;
        for (auto y: edge[x]) {
            if (!vis[y]) dfs(y);
        }
    }

    int main() {
        cin >> n >> m;
        for (int i = 1; i <= m; i ++) {
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) {
                dfs(i);
                ++cnt;
            }
        }
        cout << cnt << endl;
        return 0;
    }
};