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

    bool isPalindrome(ListNode *head) {

        if (head == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast) {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            } else {
                fast = NULL;
            }
        }

        ListNode* middleRev = reverseList(slow);
        while (head && middleRev) {
            if (head->val != middleRev->val) {
                return false;
            }
            head = head->next;
            middleRev = middleRev->next;
        }
        return true;
    }
};


int main()
{
    ListNode a(1);
    ListNode b(0);
    ListNode c(0);
    ListNode d(0);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    Solution S;
    cout << S.isPalindrome(&a) << endl;
    return 0;
}
