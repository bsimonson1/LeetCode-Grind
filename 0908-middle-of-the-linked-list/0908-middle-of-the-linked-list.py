# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        first = head
        last = head
        count = 0
        while first != None:
            count = count + 1
            first = first.next
        count = count / 2
        for i in range(count):
            last = last.next
        return last
        