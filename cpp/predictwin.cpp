#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
public:
    bool PredictTheWinner(vector<int>& nums) {
        int p1 = 0, p2 = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        p1 = bestbet(nums);

        if (p1 >= 0) {
            return true;
        } else {
            return false;
        }
    }

    int bestbet(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return ( (nums[0] > nums[1]) ? nums[0] : nums[1]);
        }

        vector<int>::iterator a = nums.begin() + 1;
        vector<int>::iterator b = nums.end();
        vector<int>::iterator p = nums.begin();
        vector<int>::iterator q = nums.end() - 1;

        vector<int> first(a, b);
        vector<int> second(p, q);

        return max(nums[0] - bestbet(first),
                   nums[nums.size()-1] - bestbet(second));
    }
};


int main() {
    Solution S;
    vector<int> test = {1, 5, 233, 7};
    cout << S.PredictTheWinner(test) << endl;
}
