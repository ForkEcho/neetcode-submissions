class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (numSet.count(num - 1)) {
                continue;
            }
            num++;
            int current_count = 1;
            while (numSet.count(num)) {
                current_count++;
                num++;
            }
            if (current_count > longest_count) {
                longest_count = current_count;
            } 
        }
        return longest_count;
    }
};