/*
 * Maximum Binary Tree
 * https://leetcode.com/problems/maximum-binary-tree/description/
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int> nums, int start, int end) {
        cout << "Enter \t " << start << "\t" << end << endl;

        if (start >= end) {
            return NULL;
        }

        int div = nums[start], loc = start;

        for (int i = start; i < end - 1; i++) {
            if (nums[i] > div) {
                div = nums[i];
                loc = i;
            }
        }

        cout << "Exit \t" << div  << "\t" << loc << endl;
        TreeNode *root = new TreeNode(div);
        root->left = helper(nums, start, loc);
        root->right = helper(nums, loc + 1, end);
        return root;
    }
};


int main() {
    Solution S;
    vector<int> test = {3,2,1,6,0,5};
    TreeNode *tree = S.constructMaximumBinaryTree(test);
}
