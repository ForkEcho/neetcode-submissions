class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sortedMap;
        for (const auto& word : strs) {
            int charMap[26] = {0};
            for (const auto& letter : word) {
                charMap[letter - 'a']++;
            }
            string keyMap;
            for (auto& count : charMap) {
                keyMap += count;
            }
            sortedMap[keyMap].push_back(word);
        }
        vector<vector<string>> sol;
        for (auto& pair: sortedMap) {
            sol.push_back(pair.second);
        }
        return sol;
    }
};