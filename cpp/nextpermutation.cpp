/*
 * Next Permutation of numbers that is greater
 * https://leetcode.com/problems/next-permutation/description/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tmp = 0, k = nums.size() - 1;
        vector<int>::iterator it;
        for (int j = nums.size() - 1; j > 0; j--) {
            if (nums[j-1] < nums[j]) {
                while (k > j-1) {
                    if (nums[k] > nums[j-1]) {
                        tmp = nums[j-1];
                        nums[j-1] = nums[k];
                        nums[k] = tmp;
                        it = nums.begin() + j;
                        sort(it, nums.end());
                        return;
                    }
                    k--;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};


int main()
{
    Solution S;
    vector<int> test = {4,2,0,2,3,2,0};
    S.nextPermutation(test);
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << "\t";
    }
}
