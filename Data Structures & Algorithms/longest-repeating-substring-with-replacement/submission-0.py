class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) == 1:
            return 1
        l = 0
        r = 0
        charDict = {}
        maxL = 0
        maxf = 0
        for r in range(len(s)):
            charDict[s[r]] = 1 + charDict.get(s[r], 0)
            maxf = max(maxf, charDict[s[r]])
            while ( k < ((r - l + 1) - maxf)):
                charDict[s[l]] -= 1
                l += 1
            print(f'{r} - {l}')
            maxL = max(maxL, ((r - l) + 1))
            r += 1
        return maxL

        