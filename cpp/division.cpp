/*
 * Division with / operator
 * https://leetcode.com/problems/divide-two-integers/description/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0, sign, tmp, i;

        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } else if (divisor == 1) {
                return INT_MIN;
            }
        }

        sign     = (dividend < 0 ? -1 : 1) * (divisor < 0 ? -1 : 1);
        long ldividend = labs(dividend);
        long ldivisor  = labs(divisor);

        while (ldividend > 0) {
            i = 0;
            while (ldividend - (ldivisor << i)  >= 0) {
                i++;
            }

            if (i == 0) {
                break;
            }

            ans += (1 << (i-1));
            ldividend -= (ldivisor << (i-1));
        }

        return sign*ans;
    }
};

int main()
{
    Solution S;
    cout << S.divide(-2147483648, 2);
    return 0;
}
