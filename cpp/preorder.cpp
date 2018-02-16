/*
 * Preorder traversal
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        return traversalIter(root, ans);
    }

    vector<int> traversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
        return ans;
    }

    vector<int> traversalIter(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }

        stack<TreeNode*> tmp;
        TreeNode *top;
        tmp.push(root);
        while(!tmp.empty()) {
            top = tmp.top();
            tmp.pop();
            ans.push_back(top->val);

            if (top->right) {
                tmp.push(top->right);
            }

            if (top->left) {
                tmp.push(top->left);
            }
        }
        return ans;
    }

};


int main()
{
    Solution S;
    TreeNode a(1), b(2), c(3);
    a.left  = &b;
    a.right = &c;

    vector<int> ans = S.preorderTraversal(&a);

    for (int i = 0; i< ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << endl;
}
