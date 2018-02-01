/*
 * Longest common prefix in a set of strings
 * https://leetcode.com/problems/longest-common-prefix/description/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string commonPfx(string s1, string s2) {
        string tmp;
        for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++,j++) {
            if (s1[i] == s2[j]) {
                tmp += s1[i];
            } else {
                break;
            }
        }
        return tmp;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string pfx;
        if (strs.empty()) {
            return pfx;
        }

        pfx = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            pfx = commonPfx(pfx, strs[i]);
        }

        return pfx;
    }

};

int main() {
    Solution S;
    vector<string> strs = { "geeks", "gee", "g"};
    cout << S.longestCommonPrefix(strs);
}
