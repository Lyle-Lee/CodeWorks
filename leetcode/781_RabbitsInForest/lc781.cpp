class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //int n = answers.size();
        //if (n == 0) return 0;
        unordered_map<int, int> count;
        for (int num: answers) ++count[num];
        int result = 0;
        for (auto &[num, cnt]: count) {
            result += (cnt + num) / (num + 1) * (num + 1); // get upper bound integers of cnt / (num + 1)
        }
        return result;
    }
};
