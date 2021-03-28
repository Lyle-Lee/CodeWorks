class Solution {
public:
    string removeDuplicates(string S) {
        int top = 0; // record valid position
        for (char ch : S) {
            if (top == 0 || S[top-1] != ch) {
                S[top++] = ch; // remove different ch to top valid position
            } else {
                top--; // valid, keep extending search area
            }
        }
        S.resize(top);
        return S;
    }
};
