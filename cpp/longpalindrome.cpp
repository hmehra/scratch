/*
 * Length of the longest palindrome from a given string
 * https://leetcode.com/problems/longest-palindrome/description/
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int>::iterator it;
        int len = 0;
        bool odd = false;
        for (int i = 0; i < s.size(); i++) {
            it = freq.find(s[i]);
            if (it == freq.end()) {
                freq[s[i]] = 1;
            } else {
                freq[s[i]] += 1;
            }
        }

        for (it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 == 0) {
                len += it->second;
            } else {
                len += it->second - 1;
                odd = true;
            }
        }
        if (odd) {
            len += 1;
        }

        return len;
    }
};


int main()
{
    Solution S;
    cout << "bb"     << "\t" << S.longestPalindrome("bb") << endl;
    cout << "dccaccd" << "\t" << S.longestPalindrome("dccaccd") << endl;
    cout << "aaaa"    << "\t" << S.longestPalindrome("aaaa") << endl;
    cout << "bananas" << "\t" << S.longestPalindrome("bananas") << endl;
    cout << S.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
}
