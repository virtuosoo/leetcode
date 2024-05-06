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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1), *cur = &dummy, *L1 = list1, *L2 = list2;
        while (L1 != nullptr && L2 != nullptr) {
            if (L1->val <= L2->val) {
                cur->next = L1;
                L1 = L1->next;
            } else {
                cur->next = L2;
                L2 = L2->next;
            }
            cur = cur->next;
        }
        cur->next = L1 == nullptr ? L2 : L1;
        return dummy.next;
    }
};