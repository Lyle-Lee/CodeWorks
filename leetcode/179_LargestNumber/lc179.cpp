class Solution {
public:
    static bool cmp(string a, string b){ // define a new priority
        return a + b > b + a;            // this defined a > b in quickSort
    }

    void swap(vector<string>& nums, int l, int r) {
        string tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }

    void quickSort(vector<string>& nums, int start, int end) {
        if (start >= end) return;
        string pivot = nums[start];
        int index = start;
        for (int i = start + 1; i <= end; ++i) {
            if (cmp(nums[i], pivot)) {
                index += 1;
                swap(nums, index, i);
            }
        }
        swap(nums, index, start);
        quickSort(nums, start, index - 1);
        quickSort(nums, index + 1, end);
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> str_nums;
        for (int i = 0; i < n; ++i) {
            str_nums.push_back(to_string(nums[i]));
        }
        quickSort(str_nums, 0, n - 1);
        string result = str_nums[0];
        if (result == "0") return "0";
        for (int i = 1; i < n; ++i) {
            result += str_nums[i];
        }
        return result;
    }
};
