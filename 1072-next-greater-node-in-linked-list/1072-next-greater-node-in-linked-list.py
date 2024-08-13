# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        res = []
        st = []
        fin = []
        while head:
            res.append(head.val)
            head = head.next

        for item in reversed(res):
            while len(st) > 0 and st[-1] <= item:
                st.pop()
            if len(st) == 0:
                fin.append(0)
            else:
                fin.append(st[-1])
            st.append(item)
        
        return reversed(fin)