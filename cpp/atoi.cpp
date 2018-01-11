
/*
 * Ascii to integer conversion
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool sign = false, once = false;
        int ans = 0, prev = 0;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == ' ') {
                if (!once) {
                    continue;
                } else {
                    return sign ? ans * -1 : ans;
                }
            } else if (c == '-') {
                sign = true;
                if (!once) {
                    once = true;
                    continue;
                } else {
                    return 0;
                }
            } else if (c == '+') {
                if (!once) {
                    once = true;
                    continue;
                } else {
                    return 0;
                }
            }

            if ( (c - '0' <= 9) && ( c - '0'  >= 0) ) {
                once = true;
                prev = ans;
                ans = ans*10 + (c - '0');
                // Overflow, return max
                if  ( (((ans-(c-'0')) / 10) != prev) || (ans < prev) ) {
                    return sign ? -2147483648 : 2147483647;
                }
            } else {
                return sign ? ans * -1 : ans;;
            }
        }
        ans = sign ? ans * -1 : ans;
        return ans;
    }
};

int main ()
{
    Solution S;
    cout << S.myAtoi("    10522545459");
}
