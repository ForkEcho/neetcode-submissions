class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        vector<int> l(1, 0);
        vector<int> r(1, 0);

        for (int i = 1, j = height.size() - 2; i < height.size(); i++, j--) {
            l.push_back(max(l[i - 1], height[i - 1]));
            //cout << "last_biggest:" << r[j + 1] <<endl;
            //cout << "last:" << height[j + 1] <<endl;
            //cout << "max:" << max(r[i - 1], height[j + 1]) <<endl;
           // cout << j << endl;

            r.push_back(max(r[i - 1], height[j + 1]));
        }

        int total = 0;
        for (int i = 0, j = height.size() - 1; i < height.size(); i++, j--) {
            if (l[i] == 0 || r[i] == 0) {
                continue;
            }
            //cout << "left:" << l[i] <<endl;
            // cout << "right:" << r[i] <<endl;
            //cout << "i:" << i <<endl;
            //cout << "height:" << height[i] <<endl;
            if (min(l[i], r[j]) < height[i]) {
                continue;
            }
                total += min(l[i], r[j]) - height[i];
                // cout << "tmp:" << (min(l[i], r[i]) - height[i]) << endl;

        }


        return total;
    }
};
