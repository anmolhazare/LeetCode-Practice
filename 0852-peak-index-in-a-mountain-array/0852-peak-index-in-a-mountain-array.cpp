class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int idx;
        for(int i=0;i<arr.size();i++){
            if(maxi<arr[i]){
                maxi=arr[i];
                idx=i;
            }
        }
        return idx;
    }
};