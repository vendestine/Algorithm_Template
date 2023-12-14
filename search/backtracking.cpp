/*
模板题

==================================================子集型回溯==================================================
lc_78. 子集 (https://leetcode.cn/problems/subsets/)
lc_90. 子集 II (https://leetcode.cn/problems/subsets-ii/)

- 输入视角
按输入每一位搜索，决策是选or不选

function<void(状态)> dfs = [&] (状态) {
    // 构造答案
    if (满足要求) 结果放入答案
    
    // 边界
    if (边界) return;

    // 非边界
    决策1, 决策2...
}
dfs(初始状态);


- 答案视角
按答案每一位搜索，决策是选哪个

function<void(状态)> dfs = [&] (状态) {
    // 构造答案
    if (满足要求) 结果放入答案
    
    // 边界
    if (边界) return;

    // 非边界
    for (决策区间) {
        当前决策；
    }
}
dfs(初始状态);


==================================================组合型回溯==================================================
lc_77. 组合(https://leetcode.cn/problems/combinations/)
lc_39. 组合总和(https://leetcode.cn/problems/combination-sum/)
lc_216. 组合总和 III(https://leetcode.cn/problems/combination-sum-iii/)
lc_40. 组合总和 II(https://leetcode.cn/problems/combination-sum-ii/)



子集型回溯基础上 函数头部加了两个剪枝
剪枝1. xxx > 需要xxx
剪枝2. 剩余xxx < 剩余需要xxx


==================================================排列型回溯==================================================
lc_46. 全排列 (https://leetcode.cn/problems/permutations)
lc_47. 全排列 II (https://leetcode.cn/problems/permutations-ii/)

排列型回溯 只有答案视角

*/


// 子集问题1 输入角度
class lc_78_01 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();

        function<void(int)> dfs = [&](int i){
            if (i == n) {
                ans.push_back(path);
                return;
            }

            // choose
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();

            //not choose
            dfs(i + 1);
        };
        
        dfs(0);
        return ans;
    }
};


// 子集问题1 答案角度
class lc_78_02 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();

        function<void(int, int)> dfs = [&](int i, int start){
            ans.push_back(path);
            
            if (i == n || start > n - 1) return;

            for (int j = start; j < n; j ++) {
                path.push_back(nums[j]);
                dfs(i + 1, j + 1);
                path.pop_back();
            }
        };
        
        dfs(0, 0);
        return ans;
    }
};


// 子集问题2 输入角度1
class lc_90_01 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            // 选
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();

            // 不选 连续相同 不选就一直不选
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
            dfs(i + 1);
        };
        dfs(0);
        return ans;
    }
};


// 子集问题2 输入角度2
class lc_90_02 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            // 不选 连续相同 不选就一直不选
            int k = i;
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
            dfs(i + 1);

            
            // 选
            path.push_back(nums[k]);
            dfs(k + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
};


// 子集问题2 输入角度3
class lc_90_03 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            
            // 不选
            dfs(i + 1);

            // 选 连续相同 选就一直选
            int cnt = 1;
            while (i + 1 < n && nums[i] == nums[i + 1]) i++, cnt++;
            for (int k = 0; k < cnt; k ++) path.push_back(nums[i]);
            dfs(i + 1);
            for (int k = 0; k < cnt; k ++)  path.pop_back(); 
        };
        dfs(0);
        return ans;
    }
};


// 子集问题2 答案角度1 层内排序去重
class lc_90_04 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int i, int start)> dfs = [&] (int i, int start) {
            ans.push_back(path);
            if (i == n || start > n - 1) return;

            for (int j = start; j < n; j ++) {
                if (j - 1 >= start && nums[j] == nums[j - 1]) continue;
                path.push_back(nums[j]);
                dfs(i + 1, j + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};


// 子集问题2 答案角度2 层内set去重
class lc_90_05 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        function<void(int i, int start)> dfs = [&] (int i, int start) {
            ans.push_back(path);
            if (i == n || start > n - 1) return;

            unordered_set<int> set;
            for (int j = start; j < n; j ++) {
                if (set.count(nums[j])) continue;
                set.insert(nums[j]);
                path.push_back(nums[j]);
                dfs(i + 1, j + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};


// 子集问题2 统计频次
class lc_90_06 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;

        // 统计每个数的频次 重建频次数组
        unordered_map<int, int> map; for (int i = 0; i < n; i ++ ) map[nums[i]]++;
        nums.clear();
        for (auto &[k ,v]: map) nums.push_back(k);
        n = nums.size();

        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            // 枚举当前数选几个
            for (int j = 0; j <= map[nums[i]]; j ++) {
                for (int k = 0; k < j; k ++) path.push_back(nums[i]);
                dfs(i + 1);
                for (int k = 0; k < j; k ++) path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};


// 组合1 输入角度
class lc_77_01 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int cnt) {
            // 剪枝
            if (cnt > k || n - i + 1 < k - cnt) return;
            
            if (i == n + 1) {
                if (cnt == k) ans.push_back(path);  //构造答案
                return;
            }

            // 选
            path.push_back(i);
            dfs(i + 1, cnt + 1);
            path.pop_back();

            // 不选
            dfs(i + 1, cnt);
        };
        dfs(1, 0);
        return ans;
    }
};

// 组合1 答案角度
class lc_77_02 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int, int)> dfs = [&](int i, int start, int cnt) {
            if (cnt > k || n - i + 1 < k - cnt) return;  // 剪枝
            if (cnt == k) ans.push_back(path);           // 构造答案
            if (i == n + 1 || start > n) return;         // 边界

            for (int j = start; j <= n; j ++) {
                path.push_back(j);
                dfs(i + 1, j + 1, cnt + 1);
                path.pop_back();
            }
        };
        dfs(1, 1, 0);
        return ans;
    }
};

// 组合总和 输入角度
class lc_39_01 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        function<void(int, int)> dfs = [&](int i, int sum) {
            if (sum > target) return;  //无限选 有剪枝1 没有剪枝2 因为当前剩余和无限大一定不满足剪枝2
            
            if (i == n) {
                if (sum == target) ans.push_back(path);
                return;
            }

            // 选
            path.push_back(candidates[i]);
            dfs(i, sum + candidates[i]);
            path.pop_back();

            // 不选
            dfs(i + 1, sum);
        };
        dfs(0, 0);
        return ans;
    }
};

// 组合总和 答案角度
class lc_39_02 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int, int)> dfs = [&](int i, int start, int sum) {
            if (sum > target) return;
            if (sum == target) ans.push_back(path);
            if (start > n - 1) return;  //无限选，答案位数没有限制

            for (int j = start; j < n; j ++) {
                path.push_back(candidates[j]);
                dfs(i + 1, j, sum + candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, 0, 0);
        return ans;
    }
};


// 组合总和3 输入角度
class lc_216_01 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int, int)> dfs = [&](int i, int cnt, int sum) {
            if (cnt > k || 9 - i + 1 < k - cnt) return;
            if (sum > n || 45 - sum < n - sum) return;
            
            // 边界
            if (i == 10) {
                if (cnt == k && sum == n) ans.push_back(path);
                return;
            }

            // 选
            path.push_back(i);
            dfs(i + 1, cnt + 1, sum + i);
            path.pop_back();

            // 不选
            dfs(i + 1, cnt, sum);
        };
        dfs(1, 0, 0);
        return ans;
    }
};

// 组合总和3 答案角度
class lc_216_02 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int, int, int)> dfs = [&](int i, int start, int cnt, int sum) {
            // 剪枝
            if (cnt > k || 9 - i + 1 < k - cnt) return;
            if (sum > n || 45 - sum < n - sum) return;
            
            // 构造答案
            if (cnt == k && sum == n) ans.push_back(path);

            // 边界
            if (i == 10 || start > 9) return;

            for (int j = start; j <= 9; j ++) {
                path.push_back(j);
                dfs(i + 1, j + 1, cnt + 1, sum + j);
                path.pop_back();
            }
        };
        dfs(1, 1, 0, 0);
        return ans;
    }
};


// 组合总和2 输入角度
class lc_40_01 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int total = accumulate(candidates.begin(), candidates.end(), 0);

        function<void(int, int)> dfs = [&] (int i, int sum) {
            if (sum > target || total - sum < target - sum) return;
        
            if (i == n) {
                if (sum == target) ans.push_back(path);
                return;
            }

            // 选
            path.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i]);
            path.pop_back();

            // 不选 连续相同 不选就一直不选
            while (i + 1 < n && candidates[i] == candidates[i + 1]) i ++;
            dfs(i + 1, sum);
        };
        dfs(0, 0);
        return ans;
    }
};


// 组合总和2 答案角度
class lc_40_02 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        int total = accumulate(candidates.begin(), candidates.end(), 0);

        function<void(int, int, int)> dfs = [&] (int i, int start, int sum) {
            if (sum > target || total - sum < target - sum) return;  //剪枝
            if (sum == target) ans.push_back(path);  //构造答案 每层结果都有可能
        
            if (i == n || start > n - 1) return; //边界

            for (int j = start; j < n; j ++) {
                if (j - 1 >= start && candidates[j] == candidates[j - 1]) continue;  //层内去重
                path.push_back(candidates[j]);
                dfs(i + 1, j + 1, sum + candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, 0, 0);
        return ans;
    }
};

// 组合总和2 统计频次
class lc_40_03 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        int total = accumulate(candidates.begin(), candidates.end(), 0);

        // 统计频次，重置输入
        unordered_map<int, int> map; for (auto &x: candidates) map[x]++;
        candidates.clear();
        for (auto &[k, v]: map) candidates.push_back(k);
        n = candidates.size();   // 输入个数变化了

        function<void(int, int)> dfs = [&] (int i, int sum) {
            if (sum > target || total - sum < target - sum) return;  //剪枝
        
            if (i == n) {
                if (sum == target) ans.push_back(path);
                return;
            }

            // 当前数用了几次
            for (int j = 0; j <= map[candidates[i]]; j ++) {
                for (int k = 0; k < j; k ++) path.push_back(candidates[i]);
                dfs(i + 1, sum + candidates[i] * j);
                for (int k = 0; k < j; k ++) path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};


// 全排列1 vis数组标记
class lc_46_01 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        bool vis[n];
        memset(vis, false, sizeof(vis));

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j ++) {
                if (!vis[j]) {
                    path.push_back(nums[j]);
                    vis[j] = true;
                    dfs(i + 1);
                    vis[j] = false;
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};


// 全排列1 状态压缩
class lc_46_02 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        int mask = 0;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j ++) {
                if (!(mask >> j & 1)) {
                    path.push_back(nums[j]);
                    mask += (1 << j);
                    dfs(i + 1);
                    mask -= (1 << j);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};


// 全排列2 层内去重
class lc_47_01 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int vis = 0;
        
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j ++ ) {
                if (j >= 1 && nums[j] == nums[j - 1] && !(vis >> j - 1 & 1)) continue;
                if (!(vis >> j & 1)) {
                    path.push_back(nums[j]);
                    vis += (1 << j);
                    dfs(i + 1);
                    vis -= (1 << j);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};

// 全排列2 层内set去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            unordered_set<int> set;
            for (int j = 0; j < n; j ++ ) {
                if (set.count(nums[j])) continue;
                if (!vis[j]) {
                    set.insert(nums[j]);
                    path.push_back(nums[j]);
                    vis[j] = true;
                    dfs(i + 1);
                    vis[j] = false;
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};



// 全排列2 直接分支间去重
class lc_47_03 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int vis = 0;
        
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < n; j ++ ) {
                if (j >= 1 && nums[j] == nums[j - 1] && (vis >> j - 1 & 1)) continue;
                if (!(vis >> j & 1)) {
                    path.push_back(nums[j]);
                    vis += (1 << j);
                    dfs(i + 1);
                    vis -= (1 << j);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};














