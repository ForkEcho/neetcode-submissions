class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol;
        int pre = 1;
        int post = 1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            sol.push_back(pre);
            int new_pre = pre * num;
            pre = new_pre;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = sol[i];
            int new_post = post * num;
            sol[i] = new_post;
            post = nums[i] * post;
        }

        return sol;
    }
};