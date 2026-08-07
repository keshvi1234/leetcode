/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> hm;

        for (int i = 0; i < n; i++) {
            hm[inorder[i]] = i;
        }

        return solve(preorder, 0, n - 1,
                     inorder, 0, n - 1, hm);
    }

    TreeNode* solve(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    unordered_map<int, int>& hm) {

        if (ps > pe || is > ie)
            return nullptr;

        int rootNode = preorder[ps];
        int pos = hm[rootNode];

        int leftSize = pos - is;

        TreeNode* root = new TreeNode(rootNode);

        root->left = solve(preorder,
                           ps + 1,
                           ps + leftSize,
                           inorder,
                           is,
                           pos - 1,
                           hm);

        root->right = solve(preorder,
                            ps + leftSize + 1,
                            pe,
                            inorder,
                            pos + 1,
                            ie,
                            hm);

        return root;
    }
};