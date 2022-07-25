class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* left,TreeNode* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->val!=right->val){
            return false;
        }
        return helper(left->left,right->right)&&helper(left->right,right->left);
    }
};
