class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int>{i+1, j+1};

            }
            else if ((numbers[i] + numbers[j]) < target) {
                i++;
            }
            else {
                j--;
            }
        }
        return std::vector<int>{0, 0};
    }
};
