/*
 * Find location of anagrams
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int a[128] = {0}, b[128] = {0};
        vector<int> ans;

        for (int i = 0; i < p.size(); i++) {
            a[p[i]] += 1;
        }

        int i = 0;
        int first = i, second = i + p.size();
        while (second < s.size() + 1) {
            memset(b, 0, 128*sizeof(int));
            while ( first < second ) {
                b[s[first++]] += 1;
            }

            if (!memcmp(a,b,128*sizeof(int))) {
                ans.push_back(i);
            }

            i++;
            first = i;
            second = i + p.size();
        }
        return ans;
    }
};


int main()
{
    Solution S;
    vector<int> ans = S.findAnagrams("abab", "ab");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
}
