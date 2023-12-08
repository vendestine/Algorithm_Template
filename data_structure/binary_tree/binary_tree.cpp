/*
模板题

=================================================构建二叉树================================================================
dmy_458. 二叉树子树和1(http://oj.daimayuan.top/course/7/problem/458)
dmy_459. 二叉树子树和2(http://oj.daimayuan.top/course/7/problem/459)


- 完全二叉树存储
完全二叉树由于特性，可以用数组来模拟  // 数组下标模拟节点编号，索引关系记录节点信息
[1]位置为根节点（1号节点），[t]位置（t号节点）的左儿子和右儿子对应的位置分别为[2t]和[2t + 1]，父亲节点的位置为[t/2];

// build以t号节点为根的子树
void build(int t) {
    updateData(t);
    build(t + t);
    build(t + t + 1);
}

---------------------------------------------------------------------------------------

- 一般二叉树存储

# 有编号 prefer存储节点编号,存储节点地址也可以；无编号 只能存储节点地址

1. 存储节点编号，root节点为1号节点
struct TreeNode{
    int l, r, fa                   // 记录左儿子，右儿子，父亲 节点编号
}


2. 存储节点地址 root指针记录root节点地址
struct TreeNode{
    TreeNode *l, *r, *fa;          // 记录左儿子，右儿子，父亲 节点地址
};


节点数组存储二叉树 （本地常用）
TreeNode a[N]        // 节点编号 = 数组索引

堆空间存储二叉树    (leetcode常用)
TreeNode * root;
root = new TreeNode(x);


=================================================遍历二叉树================================================================
dmy_430. 遍历完全二叉树(http://oj.daimayuan.top/course/7/problem/430)
dmy_431. 遍历一般二叉树(http://oj.daimayuan.top/course/7/problem/431)


- 前序遍历
void preOrder(TreeNode* p) {
    cout << p->value << endl;
    if (p->l) preOrder(p->l);
    if (p->r) preOrder(p->r);
}
preOrder(root);


- 中序遍历
void inOrder(TreeNode* p) {
    if (p->val) inOrder(p->l);
    cout < p->value << endl
    if (p->val) inOrder(p->r);
}
inOrder(root);


- 后续遍历
void postOrder(TreeNode* p) {
    if (p->l) postOrder(p->l);
    if (p->r) postOrder(p->r);
    cout << p->value << endl;
}
postOrder(root);


- 层序遍历
TreeNode * q[N];

void bfs(TreeNode * root) {
    int front = 1, rear = 0;
    q[++rear] = root;
    while (front <= rear) {
        front++;
        cout << p->value << endl;
        if (p->l) q[++rear] = p->l;
        if (p->r) q[++rear] = p->r;
    }
}
bfs(root);


*/



// 完全二叉树遍历
class dmy_430 {
    #include <bits/stdc++.h>

    using namespace std;
    int n;

    void preOrder(int t) {
        cout << t << " ";
        if (t + t <= n) preOrder(t + t);
        if (t + t + 1 <= n) preOrder(t + t + 1);
    }

    void inOrder(int t) {
        if (t + t <= n) inOrder(t + t);
        cout << t << " ";
        if (t + t + 1 <= n) inOrder(t + t + 1);
    }

    void postOrder(int t) {
        if (t + t <= n) postOrder(t + t);
        if (t + t + 1 <= n) postOrder(t + t + 1);
        cout << t << " ";
    }


    int main() {
        cin >> n;
        preOrder(1);
        cout << endl;
        inOrder(1);
        cout << endl;
        postOrder(1);
        return 0;
    }
};


// 一般二叉树遍历
class dmy_431 {
    #include <bits/stdc++.h>

    using namespace std;

    int n;
    struct TreeNode {
        int l, r, fa;
    } a[1025];

    void preOrder(int t) {
        cout << t << " ";
        if (a[t].l) preOrder(a[t].l);
        if (a[t].r) preOrder(a[t].r);
    }

    void inOrder(int t) {
        if (a[t].l) inOrder(a[t].l);
        cout << t << " ";
        if (a[t].r) inOrder(a[t].r);
    }

    void postOrder(int t) {
        if (a[t].l) postOrder(a[t].l);
        if (a[t].r) postOrder(a[t].r);
        cout << t << " ";
    }


    int main() {
        cin >> n;

        for (int i = 1; i <= n; i ++) {
            int x, y;
            cin >> x >> y;
            if (x) a[i].l = x, a[x].fa = i;
            if (y) a[i].r = y, a[y].fa = i;
        }

        preOrder(1);
        cout << endl;
        inOrder(1);
        cout << endl;
        postOrder(1);
        return 0;
    }
};


// 二叉树的子树和1
class dmy_458 {
    #include <bits/stdc++.h>

    using namespace std;

    int n, sum;
    struct TreeNode {
        int value;
        int l, r, fa;
    } a[1001];

    void order(int t) {
        sum += a[t].value;
        if (a[t].l) order(a[t].l);
        if (a[t].r) order(a[t].r);
    }

    int main() {
        cin >> n;

        for (int i = 1; i <= n; i ++) {
            int x, y;
            cin >> x >> y;
            if (x) a[i].l = x, a[x].fa = i;
            if (y) a[i].r = y, a[y].fa = i;
        }

        for (int i = 1; i <= n; i ++) cin >> a[i].value;
        for (int i = 1; i <= n; i ++) {
            sum = 0;
            order(i);
            cout << sum << " ";
        }
        return 0;
    }
};


// 二叉树子树和2
class dmy_459 {
    #include <bits/stdc++.h>

    using namespace std;

    const int N = 1000000;

    int n, v[N + 1];
    struct TreeNode {
        int value;
        int l, r, fa;
    } a[N + 1];

    int solve(int t) {
        int x = a[t].value;
        if (a[t].l) x += solve(a[t].l);
        if (a[t].r) x += solve(a[t].r);
        v[t] = x;
        return x;
    }

    int main() {
        cin >> n;

        for (int i = 1; i <= n; i ++) {
            int x, y;
            cin >> x >> y;
            if (x) a[i].l = x, a[x].fa = i;
            if (y) a[i].r = y, a[y].fa = i;
        }

        for (int i = 1; i <= n; i ++) cin >> a[i].value;
        solve(1);
        for (int i = 1; i <= n; i ++) cout << v[i] << " ";
        return 0;
    }
};
