class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> seen;
        vector<int> vt;
        for(int i=0;i<numbers.size();i++){
            if(seen.count(target-numbers[i])==1){
                vt.push_back(seen[target-numbers[i]]+1);
                vt.push_back(i+1);
                return vt;
            }
            seen[numbers[i]]=i;
        }
        return vt;
    }
};
