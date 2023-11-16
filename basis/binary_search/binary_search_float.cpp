/*
模板题
lc_69. x 的平方根 # 分界线法和左右边界法除了初始化不同，其余都一样


- 设置esp法
const double eps = 1e-(k + 2);   // eps 表示精度，一般多取两位，k为保留位数
while (l + eps < r)
{
    double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
}

- 规定循环次数法
for (int i = 0; i < 100; i++) {
	double mid = (l + r) / 2;
	if (check(mid)) r = mid; 
	else l = mid;	
}
*/

// 设置esp法
class lc_69_1 {
public:
    int mySqrt(int x) {
        double l = 0, r = 2e16;
        const double eps = 1e-7;
        while (l + eps < r) {
            double mid = (l + r) / 2;
            if (mid * mid >= x) r = mid;
            else l = mid;
        }
        return (int)r;
    }
};

// 规定循环次数法
class lc_69_2 {
public:
    int mySqrt(int x) {
        double l = 0, r = 2e16;
        for (int i = 0; i < 100; i ++) {
            double mid = (l + r) / 2;
            if (mid * mid >= x) r = mid;
            else l = mid;
        }
        return (int)r;
    }
};

