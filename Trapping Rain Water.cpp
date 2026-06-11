class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int left_max[n];
        int right_max[n];
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            if (height[i] > left_max[i - 1]) {
                left_max[i] = height[i];
            } else {
                left_max[i] = left_max[i - 1];
            }
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > right_max[i + 1]) {
                right_max[i] = height[i];
            } else {
                right_max[i] = right_max[i + 1];
            }
        }
        int total_water = 0;
        for (int i = 0; i < n; i++) {
            int lower_boundary = (left_max[i] < right_max[i]) ? left_max[i] : right_max[i];
            total_water += lower_boundary - height[i];
        }
        return total_water;
    }
};
