# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:

        if not lists or len(lists) == 0:
            return None
        
        while len(lists) > 1:
            mergedList = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                mergedList.append(self.mergeList(l1, l2))
            lists = mergedList

        return lists[0]
            
    
    def mergeList(self, l1, l2):
        dummy = ListNode()
        tmp1 = l1
        tmp2 = l2
        prev = dummy
        while (tmp1 and tmp2):
            prev1, prev2, = tmp1, tmp2
            if prev1.val < prev2.val:
                tmp1 = tmp1.next
                prev.next = prev1
                prev = prev1
            else:
                tmp2 = tmp2.next
                prev.next = prev2
                prev = prev2
        prev.next = tmp1 if tmp2 == None else tmp2
        return dummy.next
            


                
            



        