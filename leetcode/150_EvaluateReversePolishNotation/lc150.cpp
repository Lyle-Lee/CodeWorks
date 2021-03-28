class Solution {
public:
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
