class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int res=1;
        set<int> s;
        int n = arr.size();
        for(int i=0;i<n;i++)
            s.insert(arr[i]);
        
        for(auto i:s){
            if(i>0) {
                if(i<=res)
                    res++;
                else
                    break;
            }
        }
        return res;
    }
};