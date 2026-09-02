class Solution {
public:

    string encode(vector<string>& strs) {
        string sol;
        for (const auto& str : strs) {
            sol += intToPaddedString(str.size());
            for (const auto& letter : str) {
                sol += letter;
            }
        }
        return sol;
    }

    vector<string> decode(string s) {
        vector<string> sol;
        string word;
        if (s.size() == 0) {
            return sol;
        }

        int next_count = stoi(s.substr(0,3)) + 3;
        cout << s << endl;

        for (int i = 3; i < s.size(); i++) {
            string letter = {s[i]};

            
            if (i == next_count) {
                i += 2;
                sol.push_back(word);
                //cout << next_count << endl;
                cout << s.substr(next_count, 3) << endl;
                next_count = stoi(s.substr(next_count, 3)) + 1 + i;
                //cout << next_count << endl;
                word.clear();
                
            }
            else {
                word += letter;
            }
        }
        sol.push_back(word);
        return sol;
    }
private:
std::string intToPaddedString(int num) {
    std::ostringstream oss;
    oss << std::setw(3) << std::setfill('0') << num;
    return oss.str();
}
};
