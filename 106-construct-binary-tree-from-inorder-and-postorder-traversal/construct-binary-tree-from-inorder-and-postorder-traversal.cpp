/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(),i;
        TreeNode* root = new TreeNode(postorder[n-1]);
        for(i=0;i<n;i++){
            if(inorder[i]==postorder[n-1]) break;
        }
        vector<int> z,y,m,k;
        for(int j=0;j<i;j++) z.push_back(inorder[j]);
        for(int j=i+1;j<n;j++) y.push_back(inorder[j]);
        for(int j=0;j<n-1;j++){
            if(j<i) m.push_back(postorder[j]);
            else k.push_back(postorder[j]);
        }
        if(z.size()==0) root->left==NULL;
        else root->left=buildTree(z,m);
        if(y.size()==0) root->right==NULL;
        else root->right=buildTree(y,k);
        return root;
    }
};