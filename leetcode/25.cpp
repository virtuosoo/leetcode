#include <bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 反转链表中间k个节点，从head到 tail，其前后分别位prev和end
    void reverseK(ListNode *prev, ListNode *head, ListNode *tail, ListNode *end) {
        ListNode *last = prev, *cur = head;
        while (cur != end) {
            ListNode *next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        prev->next = last;
        head->next = end;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head, *tail, *prev = dummy, *end;
        while (cur) {
            tail = cur;
            for (int i = 1; i <= k - 1; ++i) {
                tail = tail->next;
                if (tail == nullptr) {
                    return dummy->next;
                }
            }
            end = tail->next;
            reverseK(prev, cur, tail, tail->next);
            prev = cur;
            cur = end;
        }
        return dummy->next;
    }
};