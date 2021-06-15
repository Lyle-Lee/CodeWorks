class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l + 2) / 3; // while r - l < 2, m1 == m2
            if (arr[m1] > arr[m1 + 1]) r = m1;
            else if (arr[m2] < arr[m2 + 1]) l = m2 + 1;
            else {
                l = m1;
                r = m2;
            }
        }
        return l;
    }
};
