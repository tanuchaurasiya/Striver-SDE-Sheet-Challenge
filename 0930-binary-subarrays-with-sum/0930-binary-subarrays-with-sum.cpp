class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int k) {
        int sum=0;
        int res=0;
        int N=A.size();
        unordered_map<int,int> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                if(sum==k)
                    res+=1; 
                if(prefixsum.find(sum-k)!=prefixsum.end())
                {
                    res+=prefixsum[sum-k];
                }
                
                prefixsum[sum]+=1;;
            }
        return res;
    }
};