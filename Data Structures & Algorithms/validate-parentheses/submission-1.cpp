#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    bool isParentheses(char ch) {
        static const unordered_set<char> parenthesesSet = {'(', ')', '{', '}', '[', ']'};
        return parenthesesSet.count(ch) > 0;
    }

    bool isLeft(char ch) {
        static const unordered_set<char> leftSet = {'(', '{', '['};
        return leftSet.count(ch) > 0;
    }

    bool isRight(char ch) {
        static const unordered_set<char> rightSet = {')', '}', ']'};
        return rightSet.count(ch) > 0;
    }

public:
    bool isValid(string s) {
        if (s.empty()) return true;

        unordered_map<char, char> rightToLeft = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> validStack;

        for (char c : s) {
            if (!isParentheses(c)) continue; // optional: skip non-parenthesis chars

            if (isLeft(c)) {
                validStack.push(c);
            } else if (isRight(c)) {
                if (validStack.empty() || validStack.top() != rightToLeft[c]) {
                    return false;
                }
                validStack.pop();
            }
        }

        return validStack.empty();
    }
};
