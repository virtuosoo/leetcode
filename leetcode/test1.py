def rev(head, tail):
    p = head
    pre = None
    while pre != tail:
        nex = p.next
        p.next = pre
        pre, p = p, nex
    return tail, head


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy
        pre = dummy
        while True:
            tail = pre
            #print(1)
            for i in range(k):
                if tail.next == None:
                    return dummy.next
                tail = tail.next
            nex = tail.next
            head, tail = rev(head, tail)
            pre.next = head
            tail.next = nex
            pre = tail
            head = nex
        return dummy.next