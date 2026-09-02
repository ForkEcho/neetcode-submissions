# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        right = head
        for i in range(n):
            right = right.next
        left = head
        prev = head
        while(right):
            right = right.next
            prev = left
            left = left.next
        prev.next = left.next
        if (left == head):
            head = left.next
        return head

        
        