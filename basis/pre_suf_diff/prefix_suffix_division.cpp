/*
模板题
lc_238. 除自身以外数组的乘积

写法1: 朴素写法，预处理前后缀数组
写法2: 优化空间，前后各遍历一次，维护pre，suf值
*/


// 朴素
class lc_238_1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int pre[n], suf[n];
        pre[0] = nums[0]; for (int i = 1; i < n; i ++ ) pre[i] = pre[i - 1] * nums[i];
        suf[n - 1] = nums[n - 1]; for (int i = n - 2; i >= 0; i --) suf[i] = suf[i + 1] * nums[i];

        vector<int> ans(n);
        ans[0] = suf[1];
        ans[n - 1] = pre[n - 2];
        for (int i = 1; i < n - 1; i ++ ) {
            ans[i] = pre[i - 1] * suf[i + 1];
        }

        return ans;
    }
};

// 优化空间
class lc_238_2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pre = 1; //初始pre i = 0时
        for (int i = 0; i < n; i ++ ) {
            ans[i] = pre;
            pre = pre * nums[i];
        }

        int suf = 1; //初始suff i = n - 1时
        for (int i = n - 1; i >= 0; i --) {
            ans[i] *= suf;
            suf = suf * nums[i];
        }

        return ans;
    }
};