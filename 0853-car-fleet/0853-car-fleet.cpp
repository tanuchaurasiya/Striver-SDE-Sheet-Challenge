class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++)
            v.push_back({position[i], speed[i]}); 
        sort(v.begin(), v.end());
        vector<float> st;
        for(int i = position.size()-1;i>=0;i--){
            float t = float((target-v[i].first)/float(v[i].second)); 
            st.push_back(t);
            if(st.size()>=2 && st[st.size()-1] <= st[st.size()-2]){
                st.pop_back();
            }
        } 
        return st.size();
    }
};