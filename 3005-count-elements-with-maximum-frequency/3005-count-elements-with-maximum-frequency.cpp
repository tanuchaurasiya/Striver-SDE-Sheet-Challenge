class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(maxi<mp[nums[i]])maxi=mp[nums[i]];
        }
        int ans=0;
        for(auto it:mp){
            if(maxi==it.second){
                ans+=maxi;
            }
        }
        return ans;
    }
};