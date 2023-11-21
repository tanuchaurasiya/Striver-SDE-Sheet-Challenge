class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mod = 1e9+7;
        for(auto num:nums){
            int rev=0;
            int orgNum=num;
            while(num>0){
                int mod = num%10;
                rev=rev*10+mod;
                num=num/10;
            }
            mp[orgNum-rev]+=1;
        }
        long long int res=0;
        
        for(auto i:mp){
            if(i.second>1){
                long long int v = i.second;
                res+=(((v%mod)*((v-1)%mod)/2))%mod;
            }
        }
        return res%mod;
    }
};