class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        t_list = list(t)
        if len(s) != len(t):
            return False
        for char in s:
            if char in t_list:
                t_list.remove(char)
            else:
                return False
        return True

        
