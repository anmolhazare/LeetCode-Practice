class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vt;
        bool flag = true;
        int temp=-1;
        for(int i=0;i<nums.size();i++){
            if(flag==true && nums[i]==target){
                flag=false;
                vt.push_back(i);
            }
            if(nums[i]==target){
                temp=i;
            }
        }
        if(flag==true){
            vt.push_back(-1);
        }
        vt.push_back(temp);
        return vt;
    }
};
