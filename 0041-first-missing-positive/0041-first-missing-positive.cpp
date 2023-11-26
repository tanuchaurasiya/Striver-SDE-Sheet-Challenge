class Solution {
public: 
//     TC - o(n) SC- o(1)
//     the missing number will always belong to {1, length(arr)+1}
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<0) 
                arr[i] = 0;
        }
         for(int i=0;i<n;i++){
            if(abs(arr[i])>=1 && abs(arr[i])<=n){
                int idx = abs(arr[i]) - 1;
                if(arr[idx]>0) 
                    arr[idx] = -arr[idx]; 
                else if(arr[idx]==0)
                    arr[idx] = -(n+1);
            }

        }
        for(int i=1;i<=n;i++)
            if(arr[i-1]>=0) return i; 
            
        return n+1;
    }
};