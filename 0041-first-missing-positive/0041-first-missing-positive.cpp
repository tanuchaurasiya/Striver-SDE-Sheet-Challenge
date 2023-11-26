class Solution {
public: 
//     TC - nlogn 
    int firstMissingPositive(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++)
            mp[arr[i]] = 1;
        
        for(int i=1;i<=n+1;i++)
            if(mp[i]==0) return i; 
            
        return -1;
    }
};