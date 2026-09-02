class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        sol = []
        nums.sort()

        def dfs(i, cur, cur_sum):
            if cur_sum == target:
                sol.append(cur.copy())
                return
            if cur_sum > target or i >= len(nums):
                return
            dfs(i + 1, cur.copy(), cur_sum)
            cur.append(nums[i])
            dfs(i, cur.copy(), cur_sum + nums[i])

        dfs(0, [], 0) 

        return sol
