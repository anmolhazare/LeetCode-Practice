class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vt;
        if(root==NULL){
            return vt;
        }
        vector<int> l = postorderTraversal(root->left);
        vt.insert(vt.end(),l.begin(),l.end());
        vector<int> r = postorderTraversal(root->right);
        vt.insert(vt.end(),r.begin(),r.end());
        vt.push_back(root->val);
        return vt;
    }
};
