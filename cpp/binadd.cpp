/*
 * Add two binary numbers
 *
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string low;
        string high;
        string ans;
        int    carry = 0, sum = 0;

        reverse(b.begin(), b.end());
        reverse(a.begin(), a.end());

        if (a.size() > b.size()) {
            low = b;
            high = a;
        } else {
            low = a;
            high = b;
        }

        for (int i = 0; i < low.size(); i++) {
            sum = carry + (low[i] - '0') + (high[i] - '0');
            if (sum == 0) {
                carry = 0;
                ans.append("0");
            } else if (sum == 1) {
                carry = 0;
                ans.append("1");
            } else if (sum == 2) {
                carry = 1;
                ans.append("0");
            } else {
                carry = 1;
                ans.append("1");
            }
        }

        if (carry == 0) {
            ans.append(high, low.size(), high.size() - low.size());
        } else {
            for (int i = low.size(); i < high.size(); i++) {
                sum = carry + (high[i] - '0');
                if (sum == 1) {
                    carry = 0;
                    ans.append("1");
                    ans.append(high, i + 1,
                               high.size() - i);
                    break;
                } else {
                    carry = 1;
                    ans.append("0");
                }
            }

            if (carry == 1) {
                ans.append("1");
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution S;
    cout << S.addBinary("11", "1");
}
