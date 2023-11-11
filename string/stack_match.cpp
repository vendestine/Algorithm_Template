/*
代码模板：
直接参照模板题 lc20. 有效的括号
*/

/*
lc20. 有效的括号 
模板题 
模板1：匹配and不匹配
模板2：字符分类
*/ 


// 模板1：匹配字符不入栈，然后匹配左括号出栈
class lc20_1 {
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

// 模板1：匹配字符入栈，然后匹配括号对出栈
class lc20_2 {
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

// 模板2：字符分类, 最后匹配字符永远不会入栈, 提前判断有效性
class lc20_3 {
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
