/*
模板题
- lc_209. 长度最小的子数组 #求最小，找最大的j
for (int i = 0, j = 0; i < n; i ++ ) {
    右端点i进入更新窗口
    while (满足) {
        更新res
        左端点j移出更新窗口
        左端点j移出
    }
}
特判一直不满足，左端点j没有移动过

- lc_03. 无重复字符的最长子串 #求最大，找最小的j
特判一直不满足，左端点越界
for (int i = 0, j = 0; i < n; i ++ ) {
    右端点i进入更新窗口
    while (不满足) {
        左端点j移出更新窗口
        左端点j移出
    }
    更新res
}

- lc_713. 乘积小于 K 的子数组 #求子数组数目，找满足起点 -> 找最小的j
*/

// 求最小，找最大的j； while(满足)
class lc_209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, res = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            sum += nums[i];
            while (sum >= target) {
                res = min(res, i - j + 1);
                sum -= nums[j];
                j++;
            }
        }

        // 特判
        return res == INT_MAX ? 0 : res;
    }
};

// 求最大，找最小的j；while(不满足)
class lc_03 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            map[s[i]]++;
            // 找最小的j
            while (j <= i && map[s[i]] > 1) {
                map[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};


// 求子数组个数，找满足起点 -> 找最小的j
class lc_713_1 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, prod = 1;
        if (k <= 1) return 0; //特判一直不满足，左端点越界
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            prod *= nums[i];
            while (prod >= k) {
                prod  /= nums[j];
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};

// 不特判越界问题
class lc_713_2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, prod = 1;
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            prod *= nums[i];
            while (j <= i && prod >= k) { //j <= i, 就不需要特判越界
                prod  /= nums[j];
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};







