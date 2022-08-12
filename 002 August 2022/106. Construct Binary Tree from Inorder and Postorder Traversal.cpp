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
    TreeNode* helper(vector<int> in,vector<int> po,int inS,int inE,int poS,int poE){
        if (inS > inE) {
		    return NULL;
	    }
    
	    int rootData = po[poE];
	    int rootIndex = -1;
	    for (int i = inS; i <= inE; i++) {
	    	if (in[i] == rootData) {
	    		rootIndex = i;
	    		break;
	    	}
	    }

	    int lInS = inS; 
	    int lInE = rootIndex - 1;
	    int lPoS = poS;
	    int lPoE = lInE - lInS + lPoS;
	    int rPoS = lPoE + 1;
	    int rPoE = poE-1;
	    int rInS = rootIndex + 1;
	    int rInE = inE;
        
	    TreeNode*  root = new TreeNode(rootData);
	    root->left = helper(in, po, lInS, lInE, lPoS, lPoE);
	    root->right = helper(in, po, rInS, rInE, rPoS, rPoE);
	    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
