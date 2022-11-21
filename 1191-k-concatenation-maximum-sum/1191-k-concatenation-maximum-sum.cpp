class Solution {
public:
    int mod = 1e9+7;
    int second(vector<int> &arr){
        vector<int> temp = arr;
        temp.insert(temp.end(),arr.begin(),arr.end());
        long long maxi=INT_MIN;
        long long sum = 0;
        for(int i=0;i<temp.size();i++){
            sum+=(temp[i]%mod);
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        if(maxi<0) return 0;
        return maxi;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        long long wholesum = 0;
        if(k==1){
            long long maxi=INT_MIN;
            long long sum = 0;
            for(int i=0;i<arr.size();i++){
                sum+=(arr[i]%mod);
                maxi=max(maxi,sum);
                if(sum<0) sum=0;
            }
            if(maxi<0) return 0;
            return maxi;
        }
        
        for(int i=0;i<arr.size();i++){
            wholesum+=arr[i];
        }
        
        if(wholesum<0){
            return second(arr);
        }
        
        int sec = second(arr);
        
        int aaa = (((k-2)*wholesum)+sec)%mod;
        int bbb = (k*wholesum)%mod;
        
        
        return max(aaa,bbb);
        
        
    }
};