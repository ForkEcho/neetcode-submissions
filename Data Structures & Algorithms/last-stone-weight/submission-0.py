class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq.heapify_max(stones)
        y = None
        x = None
        while len(stones) > 1: 
            y = heapq.heappop_max(stones)
            x = heapq.heappop_max(stones)
            y = y - x
            if y >= 1:
                heapq.heappush_max(stones, y)
        return stones[0] if stones else 0
            
        
            
            

            
