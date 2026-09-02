# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        h1, h2 = head, head
        while h1 and h1.next:
            h2 = h2.next
            h1 = h1.next.next


        second = h2.next
        prev = h2.next = None
        while (second):
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp

        h2 = prev
        h1 = head
        while (h2): 
            tmp = h1.next
            h1.next = h2
            h1 = tmp
            tmp = h2.next
            h2.next = h1
            h2 = tmp




        


        