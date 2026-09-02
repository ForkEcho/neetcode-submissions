class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int mid;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int hour_left = h;
            for (auto pile : piles) {
                hour_left -= ceil(static_cast<double>(pile) / mid);
            }
            cout << "hours:" << hour_left << " left:" << left << " mid:" << mid << " right:" << right << endl;

            if (hour_left >= 0) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

        }
        return left;
    }
};