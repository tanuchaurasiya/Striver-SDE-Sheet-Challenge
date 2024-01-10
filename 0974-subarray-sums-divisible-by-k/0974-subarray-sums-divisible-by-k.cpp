class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
	    mp[0]=1;
        int n=arr.size();
	    
	    int sum = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++) {
	        sum += arr[i];
	        int rem = sum%k;
	        if(rem < 0) rem += k;
	        ans +=mp[rem];
	        mp[rem]++;
	        
	    }
	    return ans;
    }
};