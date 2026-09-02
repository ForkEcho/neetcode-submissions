class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0 
        r = len(nums) - 1

        while (l <= r):
            m = l + ((r - l) // 2)

            print(f'{l}-{m}-{r}')
            if (nums[m] == target):
                return m
            if (nums[r] < nums[m]):
                if ((target > nums[m]) or (target < nums[l])):
                    l = m + 1
                else:
                    r = m - 1
            elif (nums[l] > nums[m]):
                if ((target < nums[m]) or (target >= nums[l])):
                    r = m - 1
                else:
                    l = m + 1
            else:
                if (target < nums[m]):
                    r = m - 1
                else:
                    l = m + 1
        return -1

                