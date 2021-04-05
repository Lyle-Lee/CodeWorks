class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        while (m >= 0 || n > 0) {
            if (m == 0) {
                while (n) {
                    nums1[n-1] = nums2[n-1];
                    n--;
                }
            }
            if (n == 0) break; // if not break, m > 0 && n > 0, which means compare can be done, put last ones to array first
            if (nums1[m-1] <= nums2[n-1]) {
                nums1[m+n-1] = nums2[n-1];
                n--;
            } else {
                nums1[m+n-1] = nums1[m-1];
                m--;
            }
        }
    }
};
