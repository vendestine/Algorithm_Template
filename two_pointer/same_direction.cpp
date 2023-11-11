/*
代码模板：
参照模板题 lc209. 长度最小的子数组
*/

/*
lc209. 长度最小的子数组 模板题
for (int i = 0, j = 0; i < n; i ++ ) {
    右端点进入更新
    while (满足) {
        更新res
        左端点移出更新
        左端点移出
    }
}
*/

// 找最大的j while（满足）
class lc209 {
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

        // 有可能窗口从来没有移动过
        return res == INT_MAX ? 0 : res;
    }
};