class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;
        int c_left = height.at(0);
        int c_right = height.at(height.size()-1);
        left.push_back(c_left);
        right.push_back(c_right);
        for(int i=1;i<height.size();i++){
            c_left = max(c_left,height[i]);
            left.push_back(c_left);
            c_right = max(c_right,height[height.size()-i-1]);
            right.push_back(c_right);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=(min(left[i],right[i]))-height[i];
        }
        return ans;
    }
};
