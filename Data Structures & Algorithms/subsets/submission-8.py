class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        sol = [[]]
        for i in range(len(nums)):
            new_sol = []
            for j in range(len(sol)):
                new_sol.append((sol[j].copy()) + [nums[i]])
            sol.extend(new_sol)

        return sol
