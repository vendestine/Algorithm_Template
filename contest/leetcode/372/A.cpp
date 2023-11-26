/*
A. 使三个字符串相等 (https://leetcode.cn/problems/make-three-strings-equal/description/)
*/

// 周赛code pass
class a_pass {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int len = min({s1.size(), s2.size(), s3.size()});

        int cnt = 0;
        for (int i = 0; i < len; i ++) {
            if (s1[i] == s2[i] && s2[i] == s3[i]) cnt++;
            else break;
        }

        if (cnt < 1) return -1;
        else return s1.size() + s2.size() + s3.size() - 3*cnt;
    }
};