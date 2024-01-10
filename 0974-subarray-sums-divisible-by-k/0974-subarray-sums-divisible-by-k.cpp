class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
	    
        int n=arr.size();
	    
	    int sum = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++) {
	        sum += arr[i];
	        int rem = sum%k;
	        if(rem < 0) rem += k;
            if(sum%k==0) ans++;
	        ans +=mp[rem];
	        mp[rem]++;
	        
	    }
	    return ans;
    }
};