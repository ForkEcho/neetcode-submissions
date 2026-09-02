# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        tmp1 = l1
        tmp2 = l2
        dummy = ListNode()
        prev = dummy
        carry = 0;
        while(tmp1 or tmp2 or carry):
            val1 = tmp1.val if tmp1 else 0
            val2 = tmp2.val if tmp2 else 0
            total = val1 + val2 + carry
            carry = total // 10
            total = total % 10

            combined = ListNode(total)    
            prev.next = combined
            prev = combined
            if tmp1:
                tmp1 = tmp1.next
            if tmp2:    
                tmp2 = tmp2.next
        return dummy.next
            