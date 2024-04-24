/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);

        if (lenA > lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }

        while (lenA != lenB) {
            headB = headB->next;
            lenB --;
        }

        while (headA != headB) {
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }

    int getLength(ListNode *head) {
        int ret = 0;
        ListNode *cur = head;
        while (cur) {
            ret ++;
            cur = cur->next;
        }
        return ret;
    }
};