class Solution {
public:
    static bool comp(vector<int>  &i1, vector<int> &i2){
        return i1[1]>i2[1];
    }
    int maximumUnits(vector<vector<int>>& arr, int W) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp); 
        int i=0;
        int res=0;
        while(i<n && W){
            if(W>=arr[i][0]){
                res+=arr[i][1]*arr[i][0];
                W-=arr[i][0];
            }
            else{
                res+=arr[i][1]*W;
                W=0;
            }
            
            i++;
        }
        return res;
    }
};