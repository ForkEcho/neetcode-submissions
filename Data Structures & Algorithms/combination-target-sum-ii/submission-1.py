class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        sol = []

        def dfs(i, curr, curr_sum):
            if curr_sum == target:
                sol.append(curr.copy())
                return
            if (i >= len(candidates)) or (target < curr_sum):
                return


            curr.append(candidates[i])
            dfs(i + 1, curr, curr_sum + candidates[i])
            curr.pop()
            j = i + 1
            while j < len(candidates) and candidates[j] == candidates[i]:
                j += 1
            dfs(j, curr, curr_sum)
        dfs(0, [], 0)

        return sol
