class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0 
        right = len(heights) - 1
        max_water = 0 
        while True:
            left_height = heights[left]
            right_height = heights[right]
            shortest_height = min(left_height, right_height)
            
            
            curr_water = (right - left) * min(heights[left], heights[right])

            if (curr_water > max_water):
                max_water = curr_water
            
            if (left_height > right_height):
                right-=1
            else: 
                left+=1
            
            if (left >= right):
                return max_water
                

