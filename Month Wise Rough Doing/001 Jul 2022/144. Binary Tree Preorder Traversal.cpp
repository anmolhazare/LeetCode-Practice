class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vt;
        if(root==NULL){
            return vt;
        }
        vt.push_back(root->val);
        vector<int> l = preorderTraversal(root->left);
        vt.insert(vt.end(),l.begin(),l.end());
        vector<int> r = preorderTraversal(root->right);
        vt.insert(vt.end(),r.begin(),r.end());
        return vt;
    }
};
