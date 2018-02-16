/*
 * Rotate a linked list by K nodes
 *
 */

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( (k == 0) || (head == NULL) ) {
            return head;
        }

        ListNode *tmp  = head;
        ListNode *last = NULL;

        int length = 0;
        while(tmp) {
            length++;
            if (tmp->next == NULL) {
                last = tmp;
            }
            tmp = tmp->next;
        }

        k = k % length;
        int n = length - k;
        tmp = head;

        while (--n) {
            tmp = tmp->next;
        }

        last->next = head;
        head = tmp->next;
        tmp->next = NULL;

        return head;
    }
};


int main()
{
    Solution S;
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    ListNode *ans = S.rotateRight(&a, 2);
    while(ans) {
        cout << ans->val << "\t";
        ans = ans->next;
    }
}
