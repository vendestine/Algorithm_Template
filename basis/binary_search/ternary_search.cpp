/*
模板题
lc_852. 山脉数组的峰顶索引 #整数三分

- 闭区间写法
while (l < r) {
    int lmid = l + (r - l) / 3;
    int rmid = r - (r - l) / 3;
    if (f(lmid) > f(rmid)) r = rmid - 1;
    else l = lmid + 1;
}
return l or r

- 开区间写法
while (l + 2 < r) {
    int lmid = (r - l) / 3 + l;
    int rmid = r - (r - l) / 3;
    if (f(lmid) > f(rmid)) r = rmid;
    else l = lmid;
}
return l + 1 or r - 1

dmy_507. 二次函数 # 求二次函数极小值 (http://oj.daimayuan.top/course/22/problem/651)

- 规定esp法
const double esp = 1e-11;
double l, r;
while (l + esp < r) {
    double lmid = l + (r - l) / 3;
    double rmid = r - (r - l) / 3;
    if (f(lmid) > f(rmid)) l = lmid;
    else r = rmid;
}
return l or r

- 设置循环法
double l, r;
for (int i = 0; i < 100; i ++) {
    double lmid = l + (r - l) / 3;
    double rmid = r - (r - l) / 3;
    if (f(lmid) > f(rmid)) l = lmid;
    else r = rmid;
}
return l or r

*/

// 整数三分 闭区间写法
class lc_852_1 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int lmid = l + (r - l) / 3;
            int rmid = r - (r - l) / 3;
            if (arr[lmid] > arr[rmid]) r = rmid - 1;
            else l = lmid + 1;
        }
        return l;
    }
};


// 整数三分 开区间写法
class lc_852_2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = n;
        while (l + 2 < r) {
            int lmid = l + (r - l) / 3;
            int rmid = r - (r - l) / 3;
            if (arr[lmid] > arr[rmid]) r = rmid;
            else l = lmid;
        }
        return l + 1;
    }
};


// 实数三分 esp法
class dmy_507_1 {
public:
    int n, a, b, c;

    double f(double x) {
        return a * x * x + b * x + c;
    }

    int solve() {
        cin >> n;
        while (n--) {
            cin >> a >> b >> c;
            const double esp = 1e-11;
            double l = -500, r = 500;
            while (l + esp < r) {
                double lmid = l + (r - l) / 3;
                double rmid = r - (r - l) / 3;
                if (f(lmid) > f(rmid)) l = lmid;
                else r = rmid;
            }
            printf("%.10f\n", f(l));
        }
        return 0;
    }
};


// 实数三分 规定循环次数
class dmy_507_2 {
public:
    int n, a, b, c;

    double f(double x) {
        return a * x * x + b * x + c;
    }

    int solve() {
        cin >> n;
        while (n--) {
            cin >> a >> b >> c;
            double l = -500, r = 500;
            for (int i = 0; i < 100; i ++) {
                double lmid = l + (r - l) / 3;
                double rmid = r - (r - l) / 3;
                if (f(lmid) > f(rmid)) l = lmid;
                else r = rmid;
            }
            printf("%.10f\n", f(l));
        }
        return 0;
    }
};
