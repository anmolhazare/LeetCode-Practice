class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if(root->val>val){
            TreeNode* l = insertIntoBST(root->left,val);
            root->left=l;
            return root;
        }else{
           TreeNode* r = insertIntoBST(root->right,val);
            root->right=r;
            return root; 
        }
    }
};
