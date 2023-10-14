# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


def rev(head, tail, end):
    pre = None
    cur = head
    while cur != end and cur != None:
        nxt = cur.next
        cur.next = pre
        pre, cur = cur, nxt

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        l, r = head, head
        res, last = None, None
        cnt = 1
        while r != None:
            nxt = r.next
            if cnt % k == 0:
                rev(l, r, r.next)
                if last != None:
                    last.next = r
                else:
                    res = r
                last = l
                l = nxt
            cnt += 1
            r = nxt
        if last.next == None:
            last.next = l
        return res