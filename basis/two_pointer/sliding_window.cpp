/*
模板题
- lc_1456. 定长子串中元音的最大数目

写法1： 不定长通用写法 本质是 while(满足长度) 然后因为while每个i只循环一次，所以if（满足长度）

窗口长度为k
for (int i = 0, j = 0; i < n; i ++ ) {
    右端点i进入更新窗口
    if (i - j + 1 == k) {
        更新res
        左端点j移出更新窗口
        左端点j移出
    }
}

写法2：枚举每一个窗口
初始化第一个窗口,更新答案
for (int i = k; i < n; i ++ ) { 
    右端点i入，更新窗口
    左端点i - k出，更新窗口
    更新res
}
*/

// 写法1 不定长通用写法
class lc_1456_1 {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), res = 0;
        unordered_set<char> set{'a', 'i', 'o', 'e', 'u'};
        
        int cnt = 0;  // 窗口维护元音数目 
        for (int i = 0, j = 0; i < n; i ++ ) {
            if (set.count(s[i])) ++cnt;

            if (i - j + 1 == k) {
                res = max(res, cnt);
                if (set.count(s[j])) --cnt;
                j++;
            }
        }
        return res;
    }
};

//写法2 枚举窗口
class lc_1456_2 {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), res = 0;
        unordered_set<char> set{'a', 'i', 'o', 'e', 'u'};
        
        // 初始化窗口
        int cnt = 0; // 窗口维护元音数目 
        for (int i = 0; i < k; i ++ ) if (set.count(s[i])) cnt++;
        res = cnt;
        
        // 枚举之后的窗口
        for (int i = k; i < n; i ++ ) {
            if (set.count(s[i])) cnt++;
            if (set.count(s[i - k])) cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};