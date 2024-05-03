struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *mid = middleNode(head);
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        ListNode *first = head, *second = reverseList(mid);
        while (first != mid || second != nullptr) {
            if (first != mid) {
                cur->next = first;
                cur = cur->next;
                first = first->next;
            }

            if (second != nullptr) {
                cur->next = second;
                cur = cur->next;
                second = second->next;
            }
        }
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            
        }
        return prev;
    }
};