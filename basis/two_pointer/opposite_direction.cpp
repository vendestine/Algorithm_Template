/*
模板题
- lc_167. 两数之和 II - 输入有序数组
int l = 0, r = n - 1;
while (l < r) {
    calc cur
    if (cur == target) 更新res
    else 移动l or r
}
*/


class lc_167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) break;
            if (sum > target) r--;
            else l++;            
        }
        return {l + 1, r + 1};
    }
};