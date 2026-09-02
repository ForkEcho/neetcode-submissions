class Solution:
    def findDuplicate(self, nums: List[int]) -> int: 
        s = 0
        f = 0
        while True:
            s = nums[s]
            f = nums[f]
            f = nums[f]
            if s == f:
                break

        s2 = 0

        while True:
            s2 = nums[s2]
            s = nums[s]
            if s == s2:
                return s