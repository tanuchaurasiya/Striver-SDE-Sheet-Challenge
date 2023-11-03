class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<int> v;
        int n=arr.size();
	    for(int i=0;i<n;i++)
	       v.push_back(arr[i]); 
	    
	    sort(v.begin(),v.end()); 
	    int i=n-1;
        set<vector<int>> s;
	    while(i>=0){
	        int j=i-1;
	        int k=0;
	        while(j>k){
	            if(v[i]+v[j]+v[k]==0)
                {
                    s.insert({v[i],v[j],v[k]});
                    k+=1;
                    j-=1;
                }
	            else if(v[i]+v[j]+v[k]>0)
	                j-=1;
	            else
	                k+=1;
	        }
	        i-=1;
	    }
	    vector<vector<int>> res;
        for (auto i:s)
            res.push_back(i);
        return res;
    }
};