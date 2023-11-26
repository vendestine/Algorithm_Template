/*
模板题

dmy_201. 队列(http://oj.daimayuan.top/course/7/problem/54) # 模拟队列
acw_829. 模拟队列(https://www.acwing.com/problem/content/831/)

- 数组模拟队列

initial：
考虑1-base，还是0-base 队列区间[front, rear]
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



dmy_206. 循环队列练习(http://oj.daimayuan.top/course/7/problem/417) # 模拟循环队列

- 数组模拟循环队列

1-base:
front = 1, rear = 0; size一定要比最长队列大(否则无法区分刚好装满和空); 元素 1 - size，初始化q[size + 1]

push:
if (rear == size) rear = 0;
q[++rear] = x;

pop:
if (front == size) front = 0;
front ++;

access:
q[rear], q[front]

isempty:
rear % size + 1 == front 空
rear % size + 1 != front 非空

query k:
if (front + k - 1 <= size) q[front + k - 1]
else q[front + k - 1 - size]
*/

