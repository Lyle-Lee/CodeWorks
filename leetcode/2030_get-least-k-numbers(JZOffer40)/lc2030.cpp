class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        if (k == arr.size()) return arr;
        return partition(arr, k, 0, arr.size() - 1);
    }

    vector<int> partition(vector<int>& arr, int k, int l, int r) {
        int i = l;
        for (int j = l + 1; j <= r; ++j) {
            if (arr[j] <= arr[l]) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i], arr[l]);
        if (i > k) return partition(arr, k, l, i - 1);
        if (i < k) return partition(arr, k, i + 1, r);
        vector<int> ans;
        ans.assign(arr.begin(), arr.begin() + k);
        return ans;
    }
};
