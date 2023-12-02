/*
模板题

=====================================================构建链表===========================================================
dmy_479. 链表中间的元素(http://oj.daimayuan.top/course/7/problem/479)

- 本地构建链表

// 定义节点类型
struct Node{
    int val;
    Node * next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
};

// 定义节点数组 存储链表
Node a[N]；

// 读入链表
# size固定写法
Node * head, *tail;
for (int i = 1; i <= size; i ++) {
    cin >> a[i].val;
    if (head == NULL) head = tail = &a[i];
    else tail = tail->next = &a[i];
}

# size不固定写法
Node * head, * tail;
string s;
getline(cin, s);
stringstream line(s);
for (int i = 1; line >> a[i].val; i ++) {
    if (head == NULL) head = tail = &a[i];
    else tail = tail->next = &a[i];
}

// 链表操作 #封装成函数
Node * func(Node * head)

// 输出链表
for (Node * p = head; p; p = p->next) p->val


================================================================================================================

*/


// 找中间节点
class dmy_479_01 {
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>

    using namespace std;

    struct Node{
        int val;
        Node * next;
        Node(): val(0), next(nullptr) {}
        Node(int x): val(x), next(nullptr) {}
    };

    Node a[100001];

    Node * middleNode(Node * head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n ++;

        int mid = n / 2;

        for (int i = 0; i < mid - 1; i ++) head = head->next;
        return head;
    }

    int main() {
        int n;
        cin >> n;

        Node * head = NULL, * tail = NULL;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].val;
            if (head == NULL) head = tail = &a[i];
            else tail = tail->next = &a[i];
        }
        
        Node * p = middleNode(head);

        cout << p->val;
        return 0;
    }
};

