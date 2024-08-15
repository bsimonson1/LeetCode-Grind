# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        vals = []
        dummy = head
        if dummy is None:
            return dummy
        while dummy is not None:
            vals.append(dummy.val)
            dummy = dummy.next
        
        summ = 0
        i = 0
        size = len(vals)
        fin = []
        zero = False
        while i < size:
            zero = False
            for j in range(i, size):
                summ += vals[j]
                if summ == 0:
                    zero = True
                    i = j + 1
                    break
            if not zero:
                fin.append(vals[i])
                i += 1
            summ = 0
        ret = ListNode()
        copy = ret
        for value in fin:
            temp = ListNode(value)
            copy.next = temp
            copy = copy.next
        return ret.next