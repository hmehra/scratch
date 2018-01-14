/*
 * Find the longest palindrome substring in a string
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), max_len = 0, start = 0;
        int i = 0, j = 0;
        bool data[len][len];
        memset(data, 0, len*len*sizeof(bool));

        // Single characters are always palindromes
        for (i = 0; i < len; i++) {
            data[i][i] = true;
            max_len = 1;
            start = i;
        }

        // Check for two letter palindroms
        for (i = 0; i < len - 1; i++) {
            j = i + 1;
            if (s[i] == s[j]) {
                data[i][j] = true;   // [i][i]   => Single letter location
                max_len = 2;         // [i][i+1] => Two letter location
                start = i;
            }
        }

        // Palindrome location(n) = true if
        // location(n) == location(n + current_len - 1) and
        // chars between are already palindrome
        // e.g length 3 palindrome check at location 0 =>
        // if location(0) == location(2) and location(1) is palindrome
        // Length 4 palindrome = length 2 palindrome + 2 end chars

        for (int cur_len = 3; cur_len <= len; cur_len++) { // Length loop
            for (i = 0; i < len - cur_len + 1; i++) { // Location loop
                j = i + cur_len - 1;
                if ( (s[i] == s[j]) && data[i+1][j-1]) {
                    data[i][j] = true;
                    max_len = cur_len;
                    start = i;
                }
            }
        }

#ifdef DEBUG
        cout << s << endl;
        cout << max_len << endl;
        cout << start << endl;
        for (i = 0;  i < len; i++) {
            for (j = 0;  j < len; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
#endif
        return s.substr(start, max_len);
    }
};

int main()
{
    Solution S;
    cout << S.longestPalindrome("abcba") << endl;
    cout << S.longestPalindrome("aaaa") << endl;
    cout << S.longestPalindrome("babad") << endl;
    cout << S.longestPalindrome("cbbd") << endl;
}
