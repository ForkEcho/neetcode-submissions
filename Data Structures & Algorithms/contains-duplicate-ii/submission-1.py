class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        num_dict = {}

        for i in range(len(nums)):
            try:
                if abs(i - num_dict[nums[i]]) <= k:
                    return True
                else:
                    num_dict[nums[i]] = i
            except KeyError:
                num_dict[nums[i]] = i
                continue
        return False
