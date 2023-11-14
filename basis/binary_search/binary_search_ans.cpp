/*
模板题
- lc_875. 爱吃香蕉的珂珂

l, r为解区间

0 | 1 --- 不合法|合法
while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
    return r; 
}

1 | 0 --- 合法 | 不合法
while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid;
    else r = mid;
    return l;
}
*/


class lc_875 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 速度越快，越可以h小时内吃完，单调性，可以二分答案
        int l = 0, r = (int) 1e9 + 1;
        
        auto check = [&] (int v) {
            int total = 0;
            for (int i = 0; i < piles.size(); i ++ ) {
                int t = (piles[i] + v - 1) / v;
                total += t;
                if (total > h) return false;
            }
            return total <= h;
        };
        
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid;
        }
        return r; 
    }
};