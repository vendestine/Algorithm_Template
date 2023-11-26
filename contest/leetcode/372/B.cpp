/*
B. 区分黑球与白球 (https://leetcode.cn/problems/separate-black-and-white-balls/description/)
*/


// 0的视角
class b_pass_01 {
public:
    long long minimumSteps(string s) {
        long long sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < s.size(); i ++) if (s[i] == '0') sum1 += i;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i ++) if (s[i] == '0') sum2 += i;

        return sum1 - sum2;
    }
};

// 1的视角
class b_pass_02 {
public:
    long long minimumSteps(string s) {
        long long sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < s.size(); i ++) if (s[i] == '1') sum1 += i;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i ++) if (s[i] == '1') sum2 += i;
        // printf("sum1: %ld, sum2: %ld", sum1, sum2);
        return sum2 - sum1;
    }
};



// 0的视角，统计0左边的1个数
class b_ans_01 {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int one = 0;
        for (char c: s) {
            if (c == '0') ans += one;
            else one++;
        }
        return ans;
    }
};

// 1的视角，统计1右边的0个数
class b_ans_02 {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int zero = 0;
        for (int i = s.size() - 1; i >= 0; i --) {
            if (s[i] == '1') ans += zero;
            else zero++;
        }
        return ans;
    }
};