class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.length();
        int state0 = leaves[0] == 'r' ? 0 : 1;
        int state1 = n + 1, state2 = n + 1;
        // state0: first part of red leaves
        // state1: middle part (yellow)
        // state2: last part of red leaves
        // use states to count change times when leaves[i] lies in each state
        for (int i = 1; i < n; ++i) {
            int isY = leaves[i] == 'y' ? 1 : 0;
            if (i == 1) state1 = state0 + 1 - isY;
            if (i == 2) state2 = state1 + isY;
            if (i >= 3) state2 = min(state1 + isY, state2 + isY);
            if (i >= 2) state1 = min(state0 + 1 - isY, state1 + 1 - isY);
            state0 += isY;
        }
        return state2;
    }
};
