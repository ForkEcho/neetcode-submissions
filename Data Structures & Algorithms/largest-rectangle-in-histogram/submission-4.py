class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        largest = 0
        for i in range(len(heights)):
            height = heights[i]
            start = i
            while(stack and stack[-1][1] > height):
                index, height_i = stack.pop()
                start = index
                largest = max(largest, (height_i * (i - index)))
            stack.append([start, height])
        while(stack):
            index, height_i = stack.pop()
            largest = max(largest, (height_i * (len(heights) - index)))
        return largest

