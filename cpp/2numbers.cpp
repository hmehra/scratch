/* Leet code - Problem 1
 * https://leetcode.com/problems/two-sum/description/
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

private:
    unordered_map<int, int> loc_map;

public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        vector<int>::iterator iter;
        int i = 0;
        for (iter = nums.begin(); iter != nums.end(); iter++) {
            unordered_map<int, int>::iterator pres;
            pres = loc_map.find(target - *iter);
            if (pres == loc_map.end()) {
                loc_map[*iter]= i;
            } else {
                vector<int> ans = {pres->second, i};
                return ans;
            }
            i++;
        }
        return {0};
    }
};


int main() {
    Solution S;
    vector<int> test = {2, 7, 10};
    vector<int> ans = S.twoSum(test, 9);
    vector<int>::iterator iter;
    for (iter = ans.begin(); iter != ans.end(); iter++)
        cout << *iter << endl;
}
