class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        while (l <= r) {
            int mid = (r + l) / 2;
            vector<int>& midMatrix = matrix[mid];
            if ((midMatrix[0] <= target) && (midMatrix[midMatrix.size() - 1] >= target)) {
                int ll = 0;
                int rr = midMatrix.size() - 1;
                while (ll <= rr) {
                    int innerMid = (rr + ll) / 2;
                    int midVal = midMatrix[innerMid];
                    if (midVal == target) {
                        return true;
                    }
                    else if (midVal < target) {
                        ll = innerMid + 1;
                    }
                    else if (midVal > target) {
                        rr = innerMid - 1;
                    }
                }
                return false;
            }
            else if (midMatrix[0] > target) {
                r = mid - 1;
            }
            else if (midMatrix[midMatrix.size() - 1] < target) {
                l = mid + 1;
            }
        }
        return false;
    }
};
