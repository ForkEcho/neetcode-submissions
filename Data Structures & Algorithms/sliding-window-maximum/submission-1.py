class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        sol = []
        queue = deque()
        l = r = 0
        while r < len(nums):
            while queue and nums[r] > nums[queue[-1]]:
                queue.pop()
            queue.append(r)
                
            if l > queue[0]:
                queue.popleft()

            if len(queue) > k :
                queue.popleft()


            if (r + 1) >= k:
                sol.append(nums[queue[0]])
                l += 1
            r += 1
        return sol




        