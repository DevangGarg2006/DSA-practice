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
    int ans=0;
    vector<int>helper(TreeNode* root){

        if(root==NULL){
            return {1,INT_MAX,INT_MIN,0};
        }

        vector<int> lft = helper(root->left);
        vector<int> rg = helper(root->right);

        if(lft[0] && rg[0] && lft[2]<root->val && rg[1]>root->val){
            int sum=lft[3]+rg[3]+root->val;
            ans=max(ans,sum);
             int mn = min(root->val, lft[1]);
            int mx = max(root->val, rg[2]);
            return {1,mn,mx,sum};
        }
        return {0,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
         helper(root);
         return ans;
    }
};