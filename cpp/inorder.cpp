/*
 * Inorder traversal
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 */

#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return traversalIter(root, ans);
    }

    vector<int> traversal(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
        return ans;
    }

    vector<int> traversalIter(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }

        stack<TreeNode*> stk;
        TreeNode *tmp = root;

        while(!stk.empty() || tmp) {
            while(tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            }

            ans.push_back(stk.top()->val);
            tmp = stk.top()->right;
            stk.pop();
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

    vector<int> ans = S.inorderTraversal(&a);

    for (int i = 0; i< ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << endl;
}
