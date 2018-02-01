#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    ListNode* reverseList(ListNode *head) {
        if ( (head == NULL) || (head->next == NULL) ) {
            return head;
        }

        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    Solution S;
    ListNode *ans = S.reverseList(&a);
    while (ans) {
        cout << ans->val << "\t";
        ans = ans->next;
    }

}
