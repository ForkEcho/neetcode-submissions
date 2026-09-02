class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int total = 0;
        vector<int> l(1, 0);
        vector<int> r(1, 0);

        for (int i = 1, j = height.size() - 2; i < height.size(); i++, j--) {
            l.push_back(max(l[i - 1], height[i - 1]));
            r.push_back(max(r[i - 1], height[j + 1]));
        }

        for (int i = 0, j = height.size() - 1; i < height.size(); i++, j--) {
            if (min(l[i], r[j]) < height[i]) {
                continue;
            }
                total += min(l[i], r[j]) - height[i];

        }
        return total;
    }
};
