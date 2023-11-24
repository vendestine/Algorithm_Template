/*
B. 2933. 高访问员工 (https://leetcode.cn/problems/high-access-employees/description/)

- 模板：将时间字符串转为分钟数
auto gao = [&](string s) {
    int x = stoi(s);
    return x / 100 * 60 + x % 100;
};

*/

// 周赛code pass
class b_pass {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        
        unordered_map<string, multiset<int>> map;
        int n = access_times.size();
        
        for (int i = 0; i < n; i ++) {
            string time = access_times[i][1];
            if (time[0] == '0' && time[1] == '0') time[0] = '2', time[1] = '4';
            else if (time[0] == '0' && time[1] != '0') time.substr(1, 3);
        }
        
        for (int i = 0; i < n; i ++) {
            string name = access_times[i][0];
            int time = stoi(access_times[i][1]);
            map[name].insert(time); 
        }
        
        for (auto &[k ,set]: map) {
            int n = set.size();
            if (n >= 3) {
                vector<int> temp;
                for (auto it = set.begin(); it != set.end(); it ++) {
                    int time = *it;
                    temp.push_back(time);
                }
                
                
                int idx = 0;
                while (idx < n) {
                    int base = temp[idx];
                    int pos = idx;
                    while (idx < n && temp[idx] - base < 100) idx++;
                    int cnt = idx - pos;
                    if (cnt >= 3) {ans.push_back(k); break;};
                    idx = pos + 1;
                }
            }
        }
        
        return ans;
    }
};

// 赛后复盘
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times) {
        unordered_map<string, vector<int>> groups;
        for (auto &p: access_times) {
            string name = p[0], s = p[1];
            int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2)); //转化为分钟数
            groups[name].push_back(t);
        }

        vector<string> ans;
        for (auto &[name, a]: groups) {
            sort(a.begin(), a.end());
            for (int i = 2; i < a.size(); i++) {
                if (a[i] - a[i - 2] < 60) {
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};