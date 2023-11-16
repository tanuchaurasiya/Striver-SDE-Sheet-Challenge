class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<vector<int>> v;
        
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(v.begin(), v.end()); 
        // for(auto k:v){
        //     for(auto k1:k)
        //         cout<<k1<<" ";
        //     cout<<endl;
        // }
       
        vector<int> res;
        int i=1;
        pq.push({v[0][1], v[0][2]}); 
        int n=tasks.size();
        long long int currtime = v[0][0];
        
        while(!pq.empty()){
            int burstTime = pq.top().first;
            int node = pq.top().second; 
            // cout<<"node and burst "<<node<<" "<<burstTime<<endl;
            pq.pop();
            currtime = currtime + burstTime; 
            res.push_back(node);
            if(i<n && v[i][0]>currtime && pq.empty())
                currtime=v[i][0];
            // cout<<"currt="<<currtime<<endl;
            while(i<n){
                if(v[i][0]<=currtime){
                    pq.push({v[i][1], v[i][2]});
                    i++;
                }
                else{
                    break;
                }
                
            }
        }
        return res;
    }
};