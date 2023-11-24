class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend()); 
        int i=0;
        int j = 1;
        int n = piles.size();
        int k=n-1; 
        int res=0;
        while(j<=k){
            res+=piles[j];
            i+=2;
            j+=2;
            k-=1;
        }
        return res;
        
    }
};