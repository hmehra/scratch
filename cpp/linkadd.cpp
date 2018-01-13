/**
 * Add two numbers in linked list
 * https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL, *tmp = NULL;
        int carry = 0;
        while (l1 && l2) {
            ListNode* sum = new ListNode;
            sum->val = (carry + l1->val + l2->val) % 10;
            sum->next = NULL;

            carry = (carry + l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;

            if (!tmp) {
                ans = sum;
                tmp = sum;
            } else {
                tmp->next = sum;
                tmp = tmp->next;
            }
        }

        if (!l1) {
            if (carry != 0) {
                while (l2) {
                    ListNode* sum = new ListNode;
                    sum->val = (carry + l2->val) % 10;
                    sum->next = NULL;

                    carry = (carry + l2->val) / 10;

                    l2 = l2->next;
                    tmp->next = sum;
                    tmp = tmp->next;

                    if (carry == 0) {
                        break;
                    }
                }
            }
            tmp->next = l2;
        }

        if (!l2) {
            if (carry != 0) {
                while (l1) {
                    ListNode* sum = new ListNode;
                    sum->val = (carry + l1->val) % 10;
                    sum->next = NULL;

                    carry = (carry + l1->val) / 10;
                    l1 = l1->next;

                    tmp->next = sum;
                    tmp = tmp->next;

                    if (carry == 0) {
                        break;
                    }
                }
            }
            tmp->next = l1;
        }

        if (carry != 0) {
            ListNode* sum = new ListNode;
            sum->val = carry;
            sum->next = NULL;
            tmp->next = sum;
        }

        return ans;
    }
};


int main()
{
    ListNode numA = ListNode(9);
    ListNode numB = ListNode(8);
    //ListNode numC = ListNode(3);

    numA.next = &numB;
    //numB.next = &numC;

    ListNode num1 = ListNode(1);
    //ListNode num2 = ListNode(6);
    //ListNode num3 = ListNode(4);

    //num1.next = &num2;
    //num2.next = &num3;

    Solution S;
    ListNode *ans = S.addTwoNumbers(&numA, &num1);
    while (ans) {
        cout << ans->val << "\t";
        ans = ans->next;
    }
}
