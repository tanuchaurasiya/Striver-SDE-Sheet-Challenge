class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<pair<int,int>> s;
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> rightGreater;
        for(int i = n2-1; i>=0 ; i--){
            if(s.empty()){
                rightGreater[nums2[i]]=-1;
                s.push({i, nums2[i]});
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    
                    if(nums2[i]>=val)
                        s.pop();
                    else{
                        rightGreater[nums2[i]] = val;
                        s.push({i, nums2[i]});
                        break;
                    }
                }
                if(s.empty()){
                    rightGreater[nums2[i]] = -1;
                    s.push({i, nums2[i]});
                }
            }
        }
        for(int i=0;i<n1;i++)
            nums1[i] = rightGreater[nums1[i]];
        return nums1;
        
    }
};