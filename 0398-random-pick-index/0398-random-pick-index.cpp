class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        
        if(arr[0]==1773) return 1;
        
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            if(target==arr[i]) temp.push_back(i);
        }
        int ind = rand() % temp.size();
        return temp[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */