class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        auto rpn = ReversePolishNotation(s);
        for (auto element: rpn) {
            if (element[0] >= '0' && element[0] <= '9') {
                nums.push(stoi(element));
            } else {
                int num = nums.top();
                nums.pop();
                switch (element[0]) {
                    case '+':
                        nums.top() += num;
                        break;
                    case '-':
                        nums.top() -= num;
                        break;
                    case '*':
                        nums.top() *= num;
                        break;
                    default:
                        nums.top() /= num;
                }
            }
        }
        return nums.top();
    }

    vector<string> ReversePolishNotation(string s) {
        stack<char> stk;
        vector<string> ans;
        int idx = 0, n = s.length();
        while (idx < n) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                string digit = "";
                while (idx < n && s[idx] >= '0' && s[idx] <= '9') {
                    digit += s[idx];
                    ++idx;
                }
                ans.push_back(digit);
            } else if (s[idx] != ')') {
                if (stk.empty()) {
                    stk.push(s[idx]);
                } else { // pop all element at top of stk to ans if its priority >= s[idx]
                    if (s[idx] == '+' || s[idx] == '-') {
                        while (!stk.empty() && stk.top() != '(') {
                            ans.push_back({stk.top()});
                            stk.pop();
                        }
                    } else if (s[idx] == '*' || s[idx] == '/') {
                        while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                            ans.push_back({stk.top()});
                            stk.pop();
                        }
                    }
                    stk.push(s[idx]);
                }
                ++idx;
            } else {
                while (stk.top() != '(') {
                    ans.push_back({stk.top()});
                    stk.pop();
                }
                stk.pop();
                ++idx;
            }
        }
        while (!stk.empty()) {
            ans.push_back({stk.top()});
            stk.pop();
        }
        return ans;
    }
};
