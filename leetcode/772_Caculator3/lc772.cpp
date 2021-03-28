class Solution {
public:
    int calculate(string s) {
        vector<string> suffix;
        stack<string> sig_stk;
        int t = 0;
        while (t < s.length()) {
            if (s[t] == ' ') {
                t++;
            } else if (isdigit(s[t])) {
                long num = 0;
                while (t < s.length() && isdigit(s[t])) {
                    num = num * 10 + s[t] - '0';
                    t++;
                }
                suffix.push_back(to_string(num));
            } else if (s[t] == '+' || s[t] == '-') {
                while (sig_stk.top() == "*" || sig_stk.top() == "/") {
                    string sign = sig_stk.top();
                    sig_stk.pop();
                    suffix.push_back(sign);
                }
                sig_stk.push(to_string(s[t]));
                t++;
            } else if (s[t] == ')') {
                while (sig_stk.top() != "(") {
                    string sign = sig_stk.top();
                    sig_stk.pop();
                    suffix.push_back(sign);
                }
                sig_stk.pop();
                t++;
            } else {
                sig_stk.push(to_string(s[t]));
                t++;
            }
        }
        while (!sig_stk.empty()) {
            string sign = sig_stk.top();
            sig_stk.pop();
            suffix.push_back(sign);
        }
        //for (string x : suffix) std::cout << x << ' ';
        //std::cout << std::endl;
        return evalRPN(suffix);
        //return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int result;
        int num1;
        int num2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                num1 = stk.top();
                stk.pop();
                num2 = stk.top();
                stk.pop();
                if (tokens[i] == "+") stk.push(num2 + num1);
                else if (tokens[i] == "-") stk.push(num2 - num1);
                else if (tokens[i] == "*") stk.push(num2 * num1);
                else stk.push(num2 / num1);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        result = stk.top();
        stk.pop();
        return result;
    }
};
