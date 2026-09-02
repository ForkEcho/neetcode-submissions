class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> sol(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int count = 0;
            while (stk.size() != 0) {
                int tmp = temperatures[stk.top()];
                if (tmp > temperatures[i]) {
                    sol[i] = stk.top() - i;
                    break;
                } else {
                    stk.pop();
                }
            }
            stk.push(i);
            continue;
        }
        return sol;
    }
};