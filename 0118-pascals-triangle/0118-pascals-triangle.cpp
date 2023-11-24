class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1)
            return {{1}};
        if(n==2)
            return {{1},{1,1}};
        vector<vector<int>> l{{1},{1,1}};
        for(int i=2;i<n;i++){ 
            vector<int> l1;
            l1.push_back(1); 
            int j=0;
            while(j<i-1){
                l1.push_back(l[i-1][j]+l[i-1][j+1]);
                j+=1;
            }
            l1.push_back(1);
            l.push_back(l1);
       
        }
        return l;
    }
};