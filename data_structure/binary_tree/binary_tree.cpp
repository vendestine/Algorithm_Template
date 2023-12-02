/*
模板题

=================================================构建二叉树================================================================

- 完全二叉树存储
完全二叉树由于特性，可以用数组来模拟  // 数组下标模拟节点编号，索引关系记录节点信息
[1]位置为根节点（1号节点），[t]位置（t号节点）的左儿子和右儿子对应的位置分别为[2t]和[2t + 1]，父亲节点的位置为[t/2];

// build以t号节点为根的子树
void build(int t) {
    updateData(t);
    build(t + t);
    build(t + t + 1);
}

----------------------------------------------------------------

- 一般二叉树存储

1. 存储节点编号，root节点编号为1，节点数组存储二叉树
struct TreeNode{
    int value;       // 当前节点的值
    int l, r, fa     // 记录左儿子，右儿子，父亲 节点编号
}

//定义节点数组，存储二叉树
TreeNode a[N]

-----------------------------------------------------------------------

2. 存储节点地址 root指针记录root节点地址，堆空间存储二叉树
struct TreeNode{
    int value;                     // 当前节点的值
    TreeNode *l, *r, *fa;          // 记录左儿子，右儿子，父亲 节点地址
    TreeNode(int x) {value = x;}   // 构造函数
};
TreeNode * root;
root = new TreeNode(x);


=================================================遍历二叉树================================================================

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
    if (p-.val) inOrder(p->r);
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