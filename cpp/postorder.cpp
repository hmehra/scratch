/*
 * Postorder traversal
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        return traversalIter(root, ans);
    }

    vector<int> traversalIter(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return ans;
        }

        stack<TreeNode*> tmp, tmpAns;
        TreeNode *top;
        tmp.push(root);
        while(!tmp.empty()) {
            top = tmp.top();
            tmp.pop();
            tmpAns.push(top);

            if (top->left) {
                tmp.push(top->left);
            }

            if (top->right) {
                tmp.push(top->right);
            }

        }

        while(!tmpAns.empty()) {
            ans.push_back(tmpAns.top()->val);
            tmpAns.pop();
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

    vector<int> ans = S.postorderTraversal(&a);

    for (int i = 0; i< ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << endl;
}
