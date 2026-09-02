class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i{0}; i < nums.size(); i++) {
            std::unordered_map<int, int>::iterator j = map.find(target - nums[i]);
            if (j != map.end()) {
                vector<int> sol = {j->second, i};
                return sol;
            }
            map[nums[i]] = i;
        }
    }
};
