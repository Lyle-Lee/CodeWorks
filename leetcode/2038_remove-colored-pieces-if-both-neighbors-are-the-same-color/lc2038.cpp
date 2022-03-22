class Solution {
public:
    bool winnerOfGame(string colors) {
        int continueA = 0, continueB = 0, cont = 0;
        char last = '#';
        for (auto& c: colors) {
            if (last != c) {
                last = c;
                cont = 1;
            } else if (++cont >= 3) {
                c == 'A' ? ++continueA : ++continueB;
            }
        }
        return continueA > continueB;
    }
};
