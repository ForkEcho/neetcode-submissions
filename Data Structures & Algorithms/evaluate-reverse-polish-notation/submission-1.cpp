class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                if (c == "+") {
                    stk.push(left + right);
                } 
                else if (c == "-") {
                    stk.push(left - right);
                } 
                else if (c == "*") {
                    stk.push(left * right);
                } 
                else if (c == "/") {
                    stk.push(left / right);
                }
            } 
            else {
                stk.push(stoi(c));
            }
        }
        return stk.top();
    }
};
