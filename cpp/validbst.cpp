/*
 * Validate BST
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 */

#include <iostream>
#include <string>
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == NULL) {
            return true;
        }

        if (left) {
            if (root->val < left->val) {
                return false;
            }
        }

        if (right) {
            if (root->val > right->val) {
                return false;
            }
        }

        return (isValid(root->left, left, root) &&
                isValid(root->right, root, right));
    }
};

int main()
{
    Solution S;
    TreeNode a(1), b(2), c(3);
    a.left  = &b;
    a.right = &c;

    cout << S.isValidBST(&a) << endl;
}
