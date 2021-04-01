class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        int count = 1;
        int num;
        N--;
        while (N) {
            count %= 4;
            if (count == 1) {
                num = stk.top();
                stk.pop();
                stk.push(num * N);
            } else if (count == 2) {
                num = stk.top();
                stk.pop();
                stk.push(num / N);
            } else if (count == 3) {
                stk.push(N);
            } else {
                stk.push(-N);
            }
            N--;
            count++;
        }
        int result = 0;
        while(!stk.empty()) {
            num = stk.top();
            result += num;
            stk.pop();
        }
        return result;
    }
};
