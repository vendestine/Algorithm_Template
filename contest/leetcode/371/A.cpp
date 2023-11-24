/*
A. 找出强数对的最大异或值 I (https://leetcode.cn/problems/maximum-strong-pair-xor-i/description/)
*/

// 周赛code pass
class a_pass {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i ++) 
            for (int j = i; j < n; j ++) {
                int x = nums[i], y = nums[j];
                if (abs(x - y) <= min(x, y)) {
                    int val = 0;
                    for (int k = 0; k < 31; k ++) {
                        int bit = (x >> k & 1) ^ (y >> k & 1);
                        if (bit == 1) val |= (1 << k);
                    }
                    ans = max(ans, val);
                }
            }
        return ans;
    }
};

// 赛后复盘
class a_ans {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        for (auto &x: nums) {
            for (auto &y: nums) {
                if (abs(x - y) <= min(x, y)) ans = max(ans, x ^ y);
            }
        }
        return ans;
    }
};


