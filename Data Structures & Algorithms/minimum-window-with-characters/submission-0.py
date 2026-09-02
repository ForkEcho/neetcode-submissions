class Solution:
    def minWindow(self, s: str, t: str) -> str:
        min_string = ""
        min_length = float('inf')
        if len(s) < len(t):
            return min_string
        l = 0
        r = len(t) - 1
        tMap = {}
        sMap = {}
        for i in range(len(t)):
            tMap[t[i]] = 1 + tMap.get(t[i], 0)
            sMap[s[i]] = 1 + sMap.get(s[i], 0)

        target_num = len(tMap.keys())
        num = 0
        for key in tMap.keys():
            if tMap.get(key, 0) <= sMap.get(key, 0):
                num += 1
        if num == target_num:
            return s[l:r + 1]

        while (r < len(s) - 1):
            r += 1
            sMap[s[r]] = 1 + sMap.get(s[r], 0)
            if tMap.get(s[r], 0) == sMap.get(s[r], 0):
                num += 1
            print(f'{num}-{l}-{r}')
            if (num == target_num):
                while num == target_num:
                    print(l)
                    print(s[l])
                    if (r + 1 - l < min_length):
                        min_string = s[l:r + 1]
                        min_length = min(r + 1 - l, min_length)
                    sMap[s[l]] -= 1
                    if (tMap.get(s[l], 0) - 1) == sMap[s[l]]:
                        num -= 1
                    l += 1
                l -= 1
                if (tMap.get(s[l], 0) - 1) == sMap[s[l]]:
                    num += 1
                sMap[s[l]] += 1
        return min_string



