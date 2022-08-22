class Solution {
public:
    void helper(vector<vector<int>> edges,bool* checked,int n,int sv){
        checked[sv]=true;
        for(int i=0;i<n;i++){
            if(sv==i) continue;
            if(edges[sv][i]==1 && !checked[i]){
                helper(edges,checked,n,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool* checked = new bool[n];
        for(int i=0;i<n;i++){
            checked[i]=false;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!checked[i]){
                helper(isConnected,checked,n,i);
                ans++;
            }
        }
        return ans;
    }
};
