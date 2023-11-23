class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            maxx=max(maxx, arr[i]);
            prefixMax[i] = maxx;
        }
        maxx=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxx=max(maxx, arr[i]);
            suffixMax[i] = maxx;
        }
        
        
        long long res=0;
        for(int i=0;i<n;i++){
            res+=(min(prefixMax[i], suffixMax[i]) - arr[i]);
        }
        return res;   
    }
};