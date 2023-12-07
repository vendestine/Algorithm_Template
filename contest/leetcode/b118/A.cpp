/*
A. 查找包含给定字符的单词(https://leetcode.cn/problems/find-words-containing-character/description/)
*/

// 周赛解法 pass
class a_pass {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < words.size(); i ++) {
            if (words[i].find(x) != -1) ans.push_back(i);
        }

        return ans;
    }
};