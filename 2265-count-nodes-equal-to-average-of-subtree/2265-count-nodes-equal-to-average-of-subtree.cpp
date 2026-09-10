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
    pair<int,int> helper(TreeNode* root,int& cnt){
        if(root==NULL){
            return {0,0};
        }
        auto lft=helper(root->left,cnt);
        auto rght=helper(root->right,cnt);
        
        int sum=lft.first+rght.first+root->val;
        int element=lft.second+rght.second+1;

        if(sum/element==root->val){
            cnt++;
        }
        return {sum,element};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        helper(root,cnt);
        return cnt;
    }
};