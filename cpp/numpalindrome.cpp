/*
 * Number palindrome without using extra space
 * https://leetcode.com/problems/palindrome-number/description/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x == INT_MIN) {
            return false;
        }

        int ones = 0, tens = 1, tmp, last;
        tmp = abs(x)/10;
        while (tmp) {
            tens = tens * 10;
            tmp = tmp / 10;
        }

        tmp = abs(x);
        while (tmp) {
            ones = tmp % 10;
            last = tmp / tens;

            if (ones != last) {
                return false;
            }

            tmp = tmp % tens;
            tmp = tmp / 10;
            tens = tens / 100;
        }
        return true;
    }
};


int main()
{
    Solution S;
    cout << S.isPalindrome(1) << endl;
    cout << S.isPalindrome(-12) << endl;
    cout << S.isPalindrome(121) << endl;
    cout << S.isPalindrome(13) << endl;
    return 0;
}
