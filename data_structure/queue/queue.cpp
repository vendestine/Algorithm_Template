/*
模板题

################################# 模拟队列 ###########################################
dmy_201. 队列(http://oj.daimayuan.top/course/7/problem/54) 
acw_829. 模拟队列(https://www.acwing.com/problem/content/831/)

- 数组模拟队列

initial：建议1-base
队列区间[front, rear]
1-base，初始化front = 1，rear = 0，元素1 - size, 所以初始化q[size + 1]
0-base，初始化front = 0, rear = -1，元素0 - size - 1，所以初始化q[size]

push: 入队
q[++rear] = x;

pop: 出队
front ++;

access: 非空访问
q[rear] 队尾
q[front] 队头

isempty:
front <= rear 非空
front > rear 非空

query k: (从队头第k个元素）
q[front + k - 1];


################################# 模拟循环队列 ###########################################
dmy_206. 循环队列练习(http://oj.daimayuan.top/course/7/problem/417)

- 数组模拟循环队列

1-base: 队列区间[front, rear] or [front, size] + [1, rear]
front = 1, rear = 0; size一定要比最长队列大(否则无法区分刚好装满和空); 元素 1 - size，初始化q[size + 1]

push:
if (rear == size) rear = 0; //特判最后一个位置
q[++rear] = x;

pop:
if (front == size) front = 0; //特判最后一个位置
front ++;

access:
q[rear], q[front]

isempty: //判定不能改变rear
rear % size + 1 == front 空
rear % size + 1 != front 非空

query k:
if (front + k - 1 <= size) q[front + k - 1]
else q[front + k - 1 - size]

*/


// 队列 1-base
class dmy_54_01 {
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    int m, q[100010];
    string op;

    int front = 1, rear = 0;
    int main() {
        // ifstream cin("aaa.txt");
        
        cin >> m;
        while (m --) {
            cin >> op;
            if (op == "push") {
                int x;
                cin >> x;
                q[++rear] = x;            
            }
            else if (op == "pop") {
                front ++;
            }
            else {
                int k;
                cin >> k;
                cout << q[front + k - 1] << endl;
            }
        }
        return 0;
    }
};


// 队列 0-base
class dmy_54_02 {
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    int m, q[100010];
    string op;

    int front = 0, rear = -1;
    int main() {
        // ifstream cin("aaa.txt");
        
        cin >> m;
        while (m --) {
            cin >> op;
            if (op == "push") {
                int x;
                cin >> x;
                q[++rear] = x;            
            }
            else if (op == "pop") {
                front ++;
            }
            else {
                int k;
                cin >> k;
                cout << q[front + k - 1] << endl;
            }
        }
        return 0;
    }
};



// 循环队列 1-base
class dmy_417_01 {
    #include <cstdio>
    #include <fstream>

    using namespace std;

    const int len = 1001;

    int m, x, k, q[len + 1];
    char str[100];

    int front = 1, rear = 0;
    int main() {
        freopen("aaa.txt", "r", stdin);

        scanf("%d", &m);
        while (m --) {
            scanf("%s", str);
            if (str[2] == 's') {
                scanf("%d", &x);
                if (rear == len) rear = 0;
                q[++rear] = x;            
            }
            else if (str[0] == 'p') {
                if (front == len) front = 0;
                front ++;
            }
            else {
                scanf("%d", &k);
                if (front + k - 1 <= len) printf("%d\n", q[front + k - 1]);
                else printf("%d\n", q[front + k - 1 - len]);
            }
        }
        return 0;
    }
};


// 循环队列 0-base
class dmy_417_02 {
    #include <cstdio>
    #include <fstream>

    using namespace std;

    const int len = 1001;

    int m, x, k, q[len];
    char str[100];

    int front = 0, rear = -1;
    int main() {
        // freopen("aaa.txt", "r", stdin);

        scanf("%d", &m);
        while (m --) {
            scanf("%s", str);
            if (str[2] == 's') {
                scanf("%d", &x);
                if (rear == len - 1) rear = -1;
                q[++rear] = x;            
            }
            else if (str[0] == 'p') {
                if (front == len - 1) front = -1;
                front ++;
            }
            else {
                scanf("%d", &k);
                if (front + k - 1 <= len - 1) printf("%d\n", q[front + k - 1]);
                else printf("%d\n", q[front + k - 1 - len]);
            }
        }
        return 0;
    }
};




