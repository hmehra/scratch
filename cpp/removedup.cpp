/*
 * Remove duplicates from a sorted array inplace
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {1,2,3};
    cout << S.removeDuplicates(nums);
}
