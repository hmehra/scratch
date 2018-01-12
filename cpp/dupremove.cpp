/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current= head, *tmp;
        while(current && current->next) {
            if (current->val == current->next->val) {
                tmp = current->next;
                current->next = current->next->next;
                // delete(tmp);
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

int main()
{
    ListNode head(10);
    ListNode first(10);
    ListNode second(10);
    ListNode third(10);

    head.next = &first;
    first.next = &second;
    second.next = &third;

    Solution S;
    ListNode *sol = S.deleteDuplicates(&head);
    while (sol) {
        cout << sol->val << endl;
        sol = sol->next;
    }
}
