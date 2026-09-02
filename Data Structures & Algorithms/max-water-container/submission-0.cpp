class Solution {
public:
    int maxArea(vector<int>& heights) {
        int biggest_size = 0;
        for (int i = 0, j = heights.size() - 1; i < j;) {
            int left = heights[i];
            int right = heights[j];
            int size = min(left, right) * (j - i);
            cout << size << endl;
            if (size > biggest_size) {
                biggest_size = size;
            }
            
            if (left > right) {
                j--;
            }
            else {
                i++;
            }

        }
        return biggest_size;   
    }
};
