class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (hash[num] != 0) {
                return true;
            }
            else {
                hash[num]++;
            }
        }
        return false;
    }
};
