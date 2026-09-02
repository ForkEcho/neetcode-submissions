class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto i : nums) {
            int& current_count = count[i];
            current_count++;
        }
        for (auto& pair: count) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> sol;
        int k_count = 0;
        for (int i = nums.size(); i >= 0; i--) {
            vector<int>& bucket = buckets[i];
            for (auto num:bucket) {
                sol.push_back(num);
                k_count++;
                if (k_count >= k) {
                    return sol;
                }
            }
        }
        return sol;
    }
};