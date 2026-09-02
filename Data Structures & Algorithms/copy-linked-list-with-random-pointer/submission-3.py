"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        oldToCopy = {}
        tmp = head
        prev = None
        if not head:
            return None
        while(tmp):
            copy = Node(tmp.val)
            oldToCopy[tmp] = copy
            if (prev):
                prev.next = copy
            prev = copy
            tmp = tmp.next
        tmp = head
        while(tmp):
            print(tmp.val)
            if tmp.random:
                oldToCopy[tmp].random = oldToCopy[tmp.random]
            tmp = tmp.next    
        return oldToCopy[head]        
        