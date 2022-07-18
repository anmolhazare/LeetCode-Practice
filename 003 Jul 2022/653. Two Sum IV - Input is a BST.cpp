class Solution {
public:
    vector<int> helper(TreeNode* root){
        vector<int> vt;
        if(root==NULL){
            return vt;
        }
        vector<int> l = helper(root->left);
        vt.insert(vt.end(),l.begin(),l.end());
        vt.push_back(root->val);
        vector<int> r = helper(root->right);
        vt.insert(vt.end(),r.begin(),r.end());
        return vt;
    }
    bool findTarget(TreeNode* root, int k) {
       if(root==NULL){
           return false;
       }
       vector<int> vt = helper(root);
        unordered_map<int,int> seen;
        for(int i=0;i<vt.size();i++){
            if(seen.count(k-vt[i])==1){
                return true;
            }
            seen[vt[i]]++;
        }
        return false;
        
    }
};
