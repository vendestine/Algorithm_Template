/*
模板题

==================================================模拟栈==================================================
acw_828. 模拟栈 (https://www.acwing.com/problem/content/830/) 
dmy_53. 栈2 (http://oj.daimayuan.top/course/7/problem/53) # 加入query k操作

- 数组模拟栈

initial：
考虑1-base，还是0-base
1-base，初始化top = 0（表示空），元素1 - size, 所以初始化stk[size + 1]
0-base，初始化top = -1（表示空），元素0 - size - 1，所以初始化stk[size]

推荐1-base

push:
stk[++top] = x;

pop:
if (top == 0) error
--top;

access:
stk[top] 非空才能访问

isempty:
top > 0 栈不为空
top == 0 栈为空

query k: (查询从上往下第k个元素）
stk[top + 1 - k];


==================================================栈匹配==================================================
lc_20. 有效的括号(https://leetcode.cn/problems/valid-parentheses/)

- 匹配and不匹配
- 字符分类




==================================================栈序列==================================================
lc_946. 验证栈序列(https://leetcode.cn/problems/validate-stack-sequences/)

- 出栈序列
for (遍历出栈序列, l为最后入栈元素) {
    if (栈为空 || 当前pop元素不是栈顶) {
        找当前pop元素 j
        if (找不到) 不合法
        for (l + 1 ~ j) 入栈序列 依次入栈
        l = j 更新最后入栈元素
    }
    stk.pop() 此时当前pop元素为栈顶，pop
}

- 入栈序列
for (遍历入栈序列) {
    当前push元素入栈；
    while(栈顶 == pop序列[j]) {
        pop；
        j++;
    }
}
*/


// 数组模拟栈
class acw_828_01 {
    const int N = 100010;
    int stk[N], top; 

    int main()
    {
        int n;
        cin >> n;
        while (n -- )
        {
            string op;
            cin >> op;
            if (op == "push")
            {
                int x;
                cin >> x;
                stk[++top] = x;
            }
            else if (op == "pop") --top ;
            else if (op == "empty") cout << (top <= 0 ? "YES" : "NO") << endl;
            else cout << stk[top] << endl;
        }
        return 0;
    } 
};


// 可能匹配字符不入栈，然后匹配左括号出栈
class lc_20_1 {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto &c: s) {
            // match
            if (stk.size() && c == ')' && stk.top() == '(') stk.pop();
            else if (stk.size() && c == ']' && stk.top() == '[') stk.pop();
            else if (stk.size() && c == '}' && stk.top() == '{') stk.pop();

            // not match
            else stk.push(c);
        }

        return stk.empty();
    }
};

// 可能匹配字符入栈，然后匹配括号对出栈
class lc_20_2 {
public:
    bool isValid(string s) {
        string stk;

        for (auto &c: s) {
            stk.push_back(c);

            // match
            if (stk.size() >= 2 && (stk.substr(stk.size() - 2, 2) == "()" || 
            stk.substr(stk.size() - 2, 2) == "[]" || stk.substr(stk.size() - 2, 2) == "{}")) stk.pop_back(), stk.pop_back();
        }

        return stk.empty();
    }
};

// 字符分类, 最后匹配字符永远不会入栈, 提前判断有效性
class lc_20_3 {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto &c: s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else if (c == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            }
            else if (c == '}') {
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            }
            else if (c == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
            }
        }

        return stk.empty();
    }
};



// 出栈序列写法
class lc_946_01 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        for (int i = 0, l = -1; i < n; i ++) {  // l是最后入栈元素
            if (stk.empty() || stk.top() != popped[i]) { //栈为空 or 当前pop元素不是栈顶
                int j = l + 1; while (j < n && pushed[j] != popped[i]) j ++;  // 找当前pop元素j
                if (j == n) return false; // 不合法
                for (int k = l + 1; k <= j; k ++) { //将最后入栈元素后一个 - 当前pop元素依次入栈，这样才合法
                    stk.push(pushed[k]);
                }
                l = j; // 更新最后入栈元素
            }
            stk.pop();  // 此时当前pop元素为栈顶，pop 
        }
        return stk.empty() == true;
    }
};


// 入栈序列写法
class lc_946_02 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i ++) {
            stk.push(pushed[i]);
            while (stk.size() && stk.top() == popped[j]) { //循环判断出栈
                stk.pop();
                j ++;
            }
        }
        return stk.empty();
    }
};