class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        stack<int> stkIndex;
        stack<int> stkHeight;

        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            if (stkHeight.empty() || height >= stkHeight.top()) {
                stkIndex.push(i);
                stkHeight.push(height);
            }
            else {
                int last_height = stkIndex.top();
                while (!stkHeight.empty() && height < stkHeight.top()) {
                    last_height = stkIndex.top();
                    int tmp = (i - stkIndex.top()) * stkHeight.top();
                    if (tmp > largest) {
                        largest = tmp;
                    }
                    stkIndex.pop();
                    stkHeight.pop();
                }
                stkIndex.push(last_height);
                stkHeight.push(height);
            }

        }
        while (!stkHeight.empty()) {
                    int last_height = stkIndex.top();
            int tmp = (heights.size() - stkIndex.top()) * stkHeight.top();
            if (tmp > largest) {
                largest = tmp;
            }
            stkIndex.pop();
            stkHeight.pop();
        }
        return largest;
    }
};
