class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return root;
        }
        if(root->val==val){
            return root;
        }
        if(root->val>val){
            TreeNode* l = searchBST(root->left,val);
            if(l!=NULL && l->val==val){
                return l;
            }
        }else{
            TreeNode* r = searchBST(root->right,val);
            if(r!=NULL && r->val==val){
                return r;
            }
        }
        return NULL;
    }
};
