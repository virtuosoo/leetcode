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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct State {
            int val;
            ListNode* p;

            bool operator<(const State &rhs) const {
                return val > rhs.val;
            }
        };

        priority_queue<State> q;
        for (ListNode *node : lists) {
            if (node) {
                q.push(State{node->val, node});
            }
        }
        ListNode dummy(-1), *cur = &dummy;
        while (!q.empty()) {
            State s = q.top();
            q.pop();
            cur->next = s.p;
            if (s.p->next != nullptr) {
                ListNode *next = s.p->next;
                q.push(State{next->val, next});
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};