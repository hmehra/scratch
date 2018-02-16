#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> location;
        for (int i = 0; i < nums.size(); i++) {
            location[nums[i]] = i;
        }

        vector<int> ans;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < findNums.size(); i++) {
            it = location.find(findNums[i]);
            if (it == location.end()) {
                ans.push_back(-1);
            } else {
                bool push = false;
                for (int j = it->second + 1 ; j < nums.size(); j++) {
                    if (nums[j] > findNums[i]) {
                        ans.push_back(nums[j]);
                        push = true;
                        break;
                    }
                }
                if (!push) {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution S;
    vector<int> ans;
    vector<int> a = {4,1,2};
    vector<int> b = {1,3,4,2};
    ans = S.nextGreaterElement(a, b);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
}
