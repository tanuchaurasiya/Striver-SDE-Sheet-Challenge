class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        int sum=0;
        int res=0;
        int N=A.size();
        unordered_map<int,vector<int>> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                if(sum==k)
                    res+=1; 
                if(prefixsum.find(sum-k)!=prefixsum.end())
                {
                    res+=prefixsum[sum-k].size();
                }
                
                prefixsum[sum].push_back(i);
            }
        return res;
    }
};