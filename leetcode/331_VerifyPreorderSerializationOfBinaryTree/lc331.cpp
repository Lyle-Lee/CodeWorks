class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        int i = 0;
        int n = preorder.length();
        while (i < n) {
            if (preorder[i] != ',') {
                degree--;
                if (degree < 0) return false; // in_degree == out_degree
                if (preorder[i] != '#') {
                    while (isdigit(preorder[i])) i++;
                    degree += 2;
                } else {
                    i++;
                }
            }
             else {
                i++;
            }
        }
        return degree == 0;
    }
};
