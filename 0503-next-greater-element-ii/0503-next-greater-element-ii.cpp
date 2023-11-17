class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        n=n+n;
        for(int i = n-1; i>=0 ; i--){
            if(s.empty()){
                s.push({i, nums[i]});
                nums[i]=-1;
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    if(nums[i]>=val)
                        s.pop();
                    else{
                        s.push({i, nums[i]});
                        nums[i] = val;
                        break;
                    }
                }
                if(s.empty()){
                    s.push({i, nums[i]});
                    nums[i] = -1;
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n/2;i++)
            res.push_back(nums[i]);
        return res;
    }
};