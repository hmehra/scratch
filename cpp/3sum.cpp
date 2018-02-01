/*
 * Find all triplets in an array whose sum is 0
 * https://leetcode.com/problems/3sum/description/
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > ans;

        if (nums.empty()) {
            return ans;
        }

        sort(nums.begin(), nums.end());
        int sum = 0, i, j, k;

        for (int i = 0; i < nums.size(); ) {
            j = i + 1;
            k = nums.size() - 1;

            while (j < k) {
                if (j >= nums.size()) {
                    break;
                }

                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back( { nums[i], nums[j], nums[k] } );
                    j++;
                    k--;

                    // To avoid duplicates
                    while ( (j < k) && (nums[j] == nums[j-1]) ) {
                        j++;
                    }
                    while ( (j < k) && (nums[k] == nums[k+1]) ) {
                        k--;
                    }
                } else if (sum < 0) {
                    j++;
                    while ( (j < k) && (nums[j] == nums[j-1]) ) {
                        j++;
                    }
                } else {
                    k--;
                    while ( (j < k) && (nums[k] == nums[k+1]) ) {
                        k--;
                    }
                }
            }

            i++;
            while (nums[i] == nums[i-1]) {
                if (i == nums.size()) {
                    break;
                }
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> in = {-1, 0, 1, 2, -1, -4};
    vector< vector<int> > ans = S.threeSum(in);
    vector< vector<int> >::iterator i;
    vector<int>::iterator j;
    for (i = ans.begin(); i != ans.end(); i++) {
        for(j = i->begin(); j != i->end(); j++) {
            cout << *j << "\t";
        }
        cout << endl;
    }
}
