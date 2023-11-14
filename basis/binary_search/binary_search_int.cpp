/*
模板题 
- lc_34. 在排序数组中查找元素的第一个和最后一个位置

首先确定求什么
1. >= x的第一个数  < x | >= x  求>=x的右边界
2. <=x的最后一个数 <= x | > x  求<=x的左边界
假设区间是[0, n - 1]

- 红蓝染色法：1. 左闭右闭 2.左闭右开 3. 左开右闭 4. 左开右开
初始区间 l = xxx, r = xxx;
while (区间不为空) {
    if (mid满足左侧) update l
    else update r
}
return 左右边界 //根据要求确定求左or右边界，根据循环不变量确定具体左右边界是什么

- 分界线法：实际是就是左开右开
初始区间 l = -1, r = n
while (l + 1 < r) {
    if (mid满足左侧) l = mid;
    else r = mid;
}
return 左右边界 //根据要求确定求左or有边界，左边界是l，右边界是r

- 注意事项
1. 因为库函数的lower_bound 和 upper_bound 都是找右边界
求左边界的话 可以直接求（该返回值即可），或者通过右边界转化
转化规则：
>= x lower_bound
> x upper_bound --- >= x + 1
< x --- (<= x) - 1
<= x --- (> x) - 1 --- (>= x + 1) - 1

2. 求左右边界，都可能无解
右边界无解，r == n; 左边界无解l == -1;
注意左开右闭写法，mid不能下取整；如果只剩一个元素，更新l和r都不会变化，死循环；mid上去整的话可以避免

3. mid = (l + r) / 2 有可能溢出 所以写成 mid = l + (r - l) / 2
*/

class lc_34_1 {
public:
    // lower_bound  < x | >= x 找>=x的右边界

    // [l, r]左闭右闭 循环不变量 l - 1满足左侧 r + 1满足右侧
    int lower_bound1(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    }

    // [l, r)左闭又开 循环不变量 l - 1满足左侧 r满足右侧
    int lower_bound2(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    // (l, r]左开右闭 l满足左侧 r + 1满足右侧
    int lower_bound3(vector<int>& nums, int target) {
        int l = -1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] >= target) r = mid - 1;
            else l = mid;
        }
        return r + 1;
    }

    // (l, r)左开右开 l满足左侧 r满足右侧
    int lower_bound4(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid;
        }
        return r;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound1(nums, target);  // >=x右边界
        int end = lower_bound1(nums, target + 1) - 1; // <=x左边界
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        // if (end == -1 || nums[end] != target) return {-1, -1};
        return {start, end};
    }
};

class lc_34_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid;
        }
        int start = r;  // >=x右边界
        
        l = -1, r = nums.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) l = mid;
            else r = mid;
        }
        int end = l; // <=x左边界
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        // if (end == -1 || nums[end] != target) return {-1, -1};
        return {start, end};
    }
};

