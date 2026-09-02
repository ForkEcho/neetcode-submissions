class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int hour_left = h;
            for (auto pile : piles) {
                hour_left -= ceil(static_cast<double>(pile) / mid);
            }
            if (hour_left < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};