class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if (turnedOn >= 9) return ans;
        if (turnedOn == 0) ans.push_back("0:00");
        else {
            int limit = 1 << 10;
            int x = (1 << turnedOn) - 1;
            while (x < limit) { // enumrate all 10-bit nums which have exactly turnedOn 1-bits
                int h = x >> 6, m = x & 63;
                if (h < 12 && m < 60) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
                // Below is Gosper's Hack to get the next valid x.
                // Find the rightmost 1-bit that can be moved left into a 0-bit. Move it left one.
                int lowBit = x & -x;                     // eg. 001110 -> 10
                int move = x + lowBit;                   // 001110 + 10 -> 010000
                x = (((x ^ move) / lowBit) >> 2) | move; // 001110 ^ 010000 -> 011110 -> 001111 -> 000011
                                                         // 010000 | 000011 -> 010011
            }
        }
        return ans;
    }
};
