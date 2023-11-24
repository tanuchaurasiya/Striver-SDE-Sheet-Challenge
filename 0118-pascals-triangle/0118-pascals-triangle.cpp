class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1)
            return {{1}};
        if(n==2)
            return {{1},{1,1}};
        vector<int> l{1,1}; 
        vector<vector<int>> res{{1}, {1,1}};
        for(long long i=2;i<n;i++){ 
            vector<int> l1;
            l1.push_back(1); 
            int j=0;
            while(j<i-1){
                l1.push_back((l[j]+l[j+1]));
                j+=1;
            }
            l1.push_back(1);
            l = l1;
            res.push_back(l);
        }
        return res;
    }
};