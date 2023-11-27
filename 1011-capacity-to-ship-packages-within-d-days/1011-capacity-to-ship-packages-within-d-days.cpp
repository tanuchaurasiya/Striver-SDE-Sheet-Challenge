class Solution {
public:
    int help(int minCapacity, vector<int>& weights, int n){
        int daysNeeded=1;
        int currWeight=0;
        int  i = 0;
        while(i<n){
            if(currWeight+weights[i]<=minCapacity){
                currWeight+=weights[i];
                i++;
            }
            else{
                daysNeeded++;
                currWeight=weights[i];
                i++;
            }
        }
        return daysNeeded;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        if(days>N) return -1;
        int sum=0;
        int maxx=INT_MIN;
        for(int i=0;i<N;i++){
            maxx=max(maxx,weights[i]);
            sum+=weights[i];
        }
        
        int low = maxx;
        int high = sum; 
        while(low<=high){
            int mid = (low+high)/2;
            // cout<<"low="<<low<<" high="<<high<<" mid="<<mid<<endl;
            int daysAllocated = help(mid, weights, N);
            // cout<<"days Allocated="<<daysAllocated<<endl;
            if(daysAllocated<=days)
                high=mid-1;
            else
                low=mid+1;
        }
        
        return low;
    }
};