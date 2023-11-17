class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett;
        for(auto i:nums)
            sett.insert(i);
        
        int res=0;
        for(auto i:sett){
            if(sett.find(i-1)!=sett.end())
                continue;
            int count = 0;
            int x = i;
            while(sett.find(x)!=sett.end()) 
            {
                count+=1;
                x+=1;
            }
            
            res=max(res, count);
        }
        return res;
    }
};