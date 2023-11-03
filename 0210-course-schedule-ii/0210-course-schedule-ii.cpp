class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int,int> mp;
        int m = pre.size();
        
        for(int i=0;i<m;i++){
            mp[pre[i][0]]+=1;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(mp[i]==0) 
                q.push(i);
        }
         vector<int> res;
        while (!q.empty()){
            int temp=q.front();
            cout<<temp<<endl;
            res.push_back(temp);
            q.pop();
            for (auto i:pre)
            {
                if (i[1]==temp)
                {
                    mp[i[0]]-=1;
                    if(mp[i[0]]==0){
                        q.push(i[0]);
                        
            
                    }
                }
            }
            
        }
        for(auto i: mp){
            if (i.second!=0) 
                return {};
        }
        return res;
        
    }
};