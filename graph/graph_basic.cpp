/*
模板题

======================================================================图基础和存储============================================================================
dmy_596. 简单图判定(http://oj.daimayuan.top/course/14/problem/596)
dmy_567. 顶点度数统计(http://oj.daimayuan.top/course/14/problem/597)
dmy_598. 顶点度数合法性(http://oj.daimayuan.top/course/14/problem/598)
dmy_599. 竞赛图数量(http://oj.daimayuan.top/course/14/problem/599)


1. 邻接矩阵
int n, m;                    // n点数 m边数
int a[N + 1][N + 1];         // N最大点数 M最大边数

for (int i = 1; i <= m; i ++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;   //无向简单图
    a[x][y]++, a[y][x]++;    //无向非简单图
    a[x][y] = 1;             //有向简单图
    a[x][y]++;               //有向非简单图
}



2. 邻接表 
eg:无向简单图

- vector
int n, m;
vector<int> edge[N + 1];

for (int i = 1; i <= m; i ++) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
}


- 链表
int n, m, l = 0;

struct Node {
    int where;
    Node * next;
} *head[N + 1], a[2 * M + 1];

void addEdge(int x, int y) {
    a[++l].where = y;
    a[l].next = head[x];
    head[x] = &a[i];
}

*/


// 简单图判定
class dmy_596 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1000;

    int n, m, a[N + 1][N + 1];

    int main() {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i ++) {
            int x, y;
            cin >> x >> y;
            if (x == y || a[x][y]) {
                cout << "No" << endl;
                return 0;
            }
            a[x][y] = a[y][x] = 1;
        }
        cout << "Yes" << endl;
        return 0;
    }
};


// 度数
class dmy_598 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1000;

    int n, m, d[N + 1];

    int main() {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i ++) {
            int x, y;
            cin >> x >> y;
            d[x]++, d[y]++;
        }

        for (int i = 1; i <= n; i ++) cout << d[i] << " ";

        return 0;
    }
};


// 度数合法性 （非简单图）
class dmy_598 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1000;

    int main() {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            cin >> x;
            sum += x;
        }

        if (sum % 2 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        
        return 0;
    }
};


// 竞赛图数量
class dmy_599 {
    #include <bits/stdc++.h>

    using namespace std;

    int main() {
        int n;
        cin >> n;
        // 注意溢出
        long long ans = 1ll << (n * (n - 1) / 2);
        cout << ans;

        return 0;
    }
}



