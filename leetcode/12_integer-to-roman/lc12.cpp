class Solution {
public:
    string intToRoman(int num) {
        vector<int> value{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> token{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        for (int i = 0; i < value.size(); ++i) {
            int v = value[i];
            while (num >= v) {
                roman += token[i];
                num -= v;
            }
        }
        return roman;
    }
};
