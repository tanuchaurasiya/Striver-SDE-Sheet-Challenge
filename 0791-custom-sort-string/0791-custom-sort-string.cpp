class Solution {
public:
    string customSortString(string order, string s) { 
        unordered_map<char, int> mp;
        string res="";
        for(auto i:s){
            mp[i]++;
        }
        
     
      
        for(auto i:order){ 
            while(mp[i]){
                res+=i; 
                mp[i]--;
            }
        }
        
        for(auto i:mp){
            if(i.second>0){
                while(i.second){
                    res+=i.first; 
                    i.second--;
                }
            }
        }
        return res;
        
    }
};