class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> colMap;
        //unordered_map<pair<int,int>, unordered_set<char>> subMap;
        map<pair<int, int>, unordered_set<char>> subMap;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                pair<int, int> squareKey = {i / 3, j / 3};
                if (rowMap[i].count(board[i][j]) || colMap[j].count(board[i][j]) || subMap[squareKey].count(board[i][j])) {
                    return false;
                }
                rowMap[i].insert(board[i][j]);
                colMap[j].insert(board[i][j]);
                subMap[squareKey].insert(board[i][j]);
            }
        }
        return true;
    }
};