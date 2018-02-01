/*
 * Remove node from linked list n nodes before end
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head, *nth = head;

        if (n <= 0) {
            return NULL;
        } else {
            while (n > 0) {
                nth  = nth->next;
                n--;
            }
        }

        if (nth) {
            while (nth->next) {
                nth = nth->next;
                current = current->next;
            }
        }

        if (current->next == NULL) {
            return NULL;
        } else {
            if ( (current == head) && !nth ) {
                head = head->next;
            } else {
                current->next = current->next->next;
            }
        }

        return head;
    }
};

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    Solution S;
    ListNode *tmp = S.removeNthFromEnd(&a, 2);
    while (tmp) {
        cout << tmp->val << "\t";
        tmp = tmp->next;
    }
}


