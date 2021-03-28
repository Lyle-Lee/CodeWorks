class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char sign = '+';
        int n = s.length();
        int t = 0;
        int num = 0;
        while (t < n) {
            if (s[t] == ' ') {
                t++;
            } else if (isdigit(s[t])) {
                while (t < s.length() && isdigit(s[t])) {
                    num = num * 10 + int(s[t] - '0');
                    t++;
                }
            } else {
                switch (sign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                sign = s[t];
                t++;
                num = 0;
            }
            if (t == n) {
                switch (sign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                    }
                }
        }
        //for (int x : stk) std::cout << x << ' ';
        //std::cout << std::endl;
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
