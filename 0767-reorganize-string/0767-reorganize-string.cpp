class Solution {
public:
    string reorganizeString(string s) { 
        unordered_map<char, int> mp; 
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]+=1;
        } 
       
        vector<pair<int,char>> counter; 

        for(auto i:mp){  
            if(i.second > int((n+1)/2))
                return "";
            counter.push_back({i.second, i.first}); 
        }
        
        sort(counter.rbegin(),counter.rend()); 
        
        vector<char> res(n); 
        int idx=0;
        for(auto i:counter){
            
            while(i.first){
                res[idx] = i.second;
                idx+=2;
                i.first-=1;
         
                if(idx>=n)
                    idx=1;
            }
            
        }
        string op="";
        for(auto i:res)
            op+=i;
        return op;
        
        
    }
};