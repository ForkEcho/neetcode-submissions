class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i : nums)
            cout << i << " ";   
        cout << endl;

        vector<vector<int>> sol;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = nums[i] * -1;
            for (int j = 0, k = nums.size() - 1; j < k;) {
                if (((nums[j] + nums[k]) < target) || j == i) {
                    j++;
                }
                else if (((nums[j] + nums[k]) > target) || k == i) {
                    k--;
                }
                else{
                    vector<int> vec = {nums[i], nums[j] , nums[k]};
                    sort(vec.begin(), vec.end());
                    if (st.count(vec) == 0) {
                        cout << i << " " << j << " " << k << endl;
                        sol.push_back(vec);
                        st.insert(vec);
                    }
                    j++;
                    k--;
                }
            }
        }
        return sol;
    }
};
