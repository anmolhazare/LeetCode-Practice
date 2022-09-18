class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size()-1;
        int max=INT_MIN;
        while(lo<hi){
            int val = (hi-lo)*min(height[lo],height[hi]);
            if(val>max) max=val;
            
            if(height[lo]<height[hi]) lo++;
            else hi--;
        }
        return max;
    }
};
