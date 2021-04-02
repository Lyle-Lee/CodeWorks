class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end;
        int answer = 0;
        int n = height.size();
        while (start < n - 2) {
            end = start + 1;
            if (height[end] >= height[start]) {
                start++;
            } else {
                while (end < n && height[end] < height[start]) end++;
                if (end < n) {
                    for (int i = start + 1; i < end; ++i) {
                        answer += height[start] - height[i];
                        height[i] = height[start]; // fill water
                    }
                    start = end;
                } else {
                    start++;
                }
            }
        }
        start = n - 1; // scan from right, case like [4, 2, 3] would be missed
        while (start > 1) {
            end = start - 1;
            if (height[end] >= height[start]) {
                start--;
            } else {
                while (end >= 0 && height[end] < height[start]) end--;
                if (end >= 0) {
                    if (height[end] > height[start]) {
                        for (int i = start - 1; i > end; --i) answer += height[start] - height[i];
                    }
                    start = end;
                } else {
                    start--;
                }
            }
        }
        return answer;
    }
};
