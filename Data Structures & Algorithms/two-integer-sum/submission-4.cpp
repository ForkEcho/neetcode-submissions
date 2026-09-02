class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i{0}; i < nums.size(); i++) {
            auto possible_pair = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            while (possible_pair != nums.end()) {
                int j{possible_pair - nums.begin()};
                if (j != i ) {
                    vector<int> sol = {i, j};
                    return sol;
                }
                possible_pair = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            }
        }
    }
};
