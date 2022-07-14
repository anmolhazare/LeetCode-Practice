class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vt;
        if(root==NULL){
            return vt;
        }
        vector<int> left = inorderTraversal(root->left);
        vt.insert( vt.end(), left.begin(), left.end() );
        vt.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        vt.insert( vt.end(), right.begin(), right.end() );
        return vt;
    }
};
