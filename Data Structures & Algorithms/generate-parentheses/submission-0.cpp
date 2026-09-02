class Solution {
public:

    void backtrack(int open, int closed, int n, vector<string>& sol, string& stack) {
        if (open == n && closed == n){
            sol.push_back(stack);
            return;
        }
        if (open < n) {
            stack += '(';
            backtrack(open + 1, closed, n, sol, stack);
            stack.pop_back();
        }
        if (closed < open) {
            stack += (')');
            backtrack(open, closed + 1, n, sol, stack);
            stack.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string stack;
        backtrack(0, 0, n, sol, stack);
        return sol;
    }
};
