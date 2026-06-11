class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int running_sum = 0;
        int seen_at[2 * n + 1];
        for (int i = 0; i < 2 * n + 1; i++) {
            seen_at[i] = -2;
        }
        seen_at[0 + n] = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                running_sum++;
            } else {
                running_sum--;
            }
            int target_index = running_sum + n;
            if (seen_at[target_index] != -2) {
                int len = i - seen_at[target_index];
                if (len > maxLen) {
                    maxLen = len;
                }
            } else {
                seen_at[target_index] = i;
            }
        }
        return maxLen;
    }
};
