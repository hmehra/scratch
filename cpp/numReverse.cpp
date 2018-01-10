/*
 * Reverse a 32 bit integer with overflow constraints
 * https://leetcode.com/problems/reverse-integer/description/
 */

#include <iostream>

using namespace std;

class Solution {

public:
    int reverse(int x) {
        int ans = 0, prev = 0, positive = abs(x);
        bool sign = false;
        if (x < 0) {
            sign = true;
        }

        while (positive) {
            prev = ans;
            ans = ans*10 + positive % 10;
            // Check for overflow
            if ( ((ans - (positive % 10))/10) != prev) {
                return 0;
            }
            positive = positive/10;
        }
        ans = sign ? ans * (-1) : ans;
        return ans;
    }
};

int main()
{
    Solution S;
    cout << S.reverse(123) << endl;
}
