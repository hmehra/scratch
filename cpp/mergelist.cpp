/*
 * Merge two sorted linked lists
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tmp = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                if (head == NULL) {
                    head = l1;
                    tmp = head;
                } else {
                    tmp->next = l1;
                    tmp = tmp->next;
                }
                l1 = l1->next;
            } else {
                if (head == NULL) {
                    head = l2;
                    tmp = head;
                } else {
                    tmp->next = l2;
                    tmp = tmp->next;
                }
                l2 = l2->next;
            }
        }

        if (l1) {
            if (head) {
                tmp->next = l1;
            } else {
                head = l1;
            }
        }

        if (l2) {
            if (head) {
                tmp->next = l2;
            } else {
                head = l2;
            }
        }

        return head;
    }
};

int main() {
    ListNode a(0);//, b(2), c(4);
    //ListNode p(1), q(3), r(4);
    ListNode *p = NULL;

    //a.next = &b;
    // b.next = &c;
    // p.next = &q;
    // q.next = &r;

    Solution S;
    ListNode *tmp = S.mergeTwoLists(&a, p);
    while (tmp) {
        cout << tmp->val << "\t";
        tmp = tmp->next;
    }
}
