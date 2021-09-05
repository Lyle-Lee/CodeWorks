// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num1 = rand7(), num2 = rand7();
        int s = num1 + num2;
        while (s == 10 || s == 11) {
            num1 = rand7();
            num2 = rand7();
            s = num1 + num2;
        }
        if (s == 2 || s == 4) return 1;
        if (s == 3 || s == 13) return 2;
        if (s == 12 || s == 14) return 3;
        if (s == 5) return 4;
        if (s == 6) {
            if (num1 != 3) return 5;
            else return 8;
        }
        if (s == 7) {
            if (num1 != 3 && num1 != 4) return 6;
            else return 9;
        }
        if (s == 8) {
            if (num1 != 4 && num1 != 3 && num1 != 5) return 7;
            else return 8;
        }
        // s == 9
        if (num1 != 4 && num1 != 5) return 10;
        return 9;
    }
};
