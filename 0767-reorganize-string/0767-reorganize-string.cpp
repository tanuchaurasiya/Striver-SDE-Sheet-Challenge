class Solution {
public:
    string reorganizeString(string s) { 
        unordered_map<char, int> mp; 
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]+=1;
        } 
        cout<<n<<endl;
        vector<pair<int,char>> counter; 

        for(auto i:mp){ 
            char c = i.first; 
            int count = i.second;
            if(count > int((n+1)/2))
                return "";
            pair<int,char>p{count, c};
            counter.push_back(p); 
        }
        
        sort(counter.rbegin(),counter.rend()); 
        
        vector<char> res(n); 
        int idx=0;
        for(auto i:counter){
            int count = i.first;
            char c = i.second;
            
            while(count){
                res[idx] = c;
                idx+=2;
                count-=1;
         
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