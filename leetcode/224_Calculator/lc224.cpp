class Solution {
public:
    int calculate(string s) {
        stack<int> sig_stk;
        sig_stk.push(1);
        int sign = 1;
        int result = 0;
        int n = s.length();
        int index = 0;
        while (index < n) {
            if (s[index] == ' ') {
                index++;
            } else if (s[index] == '+') {
                sign = sig_stk.top();
                index++;
            } else if (s[index] == '-') {
                sign = -sig_stk.top();
                index++;
            } else if (s[index] == '(') {
                sig_stk.push(sign); // sign works for all num in brackets
                index++;
            } else if (s[index] == ')') {
                sig_stk.pop();
                index++;
            } else {
                long num = 0;
                while (index < n && s[index] >= '0' && s[index] <= '9') {
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                result += num * sign;
            }
        }
        return result;
    }
};
