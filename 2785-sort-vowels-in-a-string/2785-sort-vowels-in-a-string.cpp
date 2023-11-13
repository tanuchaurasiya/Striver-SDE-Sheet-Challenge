class Solution {
public:
    string sortVowels(string s) { 
        unordered_map<char, int> mp;
        vector<char> v{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        for(auto i:s){
            mp[i]++;
        }
        
        for(int i=0;i<s.length();i++){
            if(find(v.begin(), v.end(), s[i]) == v.end()) continue; 
            
            else{
                if(mp['A']>0){
                    s[i] = 'A'; 
                    mp['A']-=1;
                }
                else if(mp['E']>0){
                    s[i] = 'E'; 
                    mp['E']-=1;
                }
                else if(mp['I']>0){
                    s[i] = 'I'; 
                    mp['I']-=1;
                }
                else if(mp['O']>0){
                    s[i] = 'O'; 
                    mp['O']-=1;
                }
                else if(mp['U']>0){
                    s[i] = 'U'; 
                    mp['U']-=1;
                }
                
                else if(mp['a']>0){
                    s[i] = 'a'; 
                    mp['a']-=1;
                }
                else if(mp['e']>0){
                    s[i] = 'e'; 
                    mp['e']-=1;
                }
                else if(mp['i']>0){
                    s[i] = 'i'; 
                    mp['i']-=1;
                }
                else if(mp['o']>0){
                    s[i] = 'o'; 
                    mp['o']-=1;
                }
                
                else if(mp['u']>0){
                    s[i] = 'u'; 
                    mp['u']-=1;
                }
                
            }
        }
        return s;
    }
};