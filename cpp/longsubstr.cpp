/*
 * Find the longest substring with non repeating characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * Sliding window approach.
 * Use a hash map to constantly store unique chars
 * If a new char appears, add to map and increase the window size by right
 * If an existing character appears, reset the map for that character and
 * increment the window size by left
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int>::iterator it;
        int max_len = 0;
        int i = 0, j = 0;
        while ( i < s.size() && j < s.size()) {
            it = freq.find(s[j]);
            if (it == freq.end()) {
                freq[s[j]] = 1;
                j++;
#ifdef DEBUG
                cout << s[j] << "\t" << i << "\t" << j << "\t" << max_len << endl;
#endif
                max_len = max(max_len, j - i);
            } else {
                it = freq.find(s[i]);
                freq.erase(it);
                i++;
            }
        }
        return max_len;
    }
};


int main()
{
    Solution S;
    cout << S.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << S.lengthOfLongestSubstring("bbb") << endl;
    cout << S.lengthOfLongestSubstring("pwwkew") << endl;
}
