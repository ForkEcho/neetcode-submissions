class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) {
            return s.size();
        }

        int maxString = 1;
        unordered_map<char, int> mp;
        int l = 0, r = 1;
        char& lChar = s[l];
        mp[s[l]]++;
        for (; r < s.size(); r++) {
             char& rChar = s[r];
             mp[rChar]++;

            while (mp[rChar] > 1) {
                mp[lChar]--;
                l++;
                lChar = s[l];
            }
                maxString = max(maxString, (r - l + 1));
            cout << r - l + 1 << endl;

        }
        return maxString;
    }
};
