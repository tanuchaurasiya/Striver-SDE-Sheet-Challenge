class Solution {
public:
    string simplifyPath(string path) {
       vector<string> v;
        stack<string> st;
        int i=0;
        int n = path.length();
        while(i<n){
            string temp="";
            while(i<n && path[i]!='/') 
            {
                temp+=path[i];
                i++;
            }
            v.push_back(temp);
            i++;
        }
        
        for(auto ele:v){
            if((!st.empty()) && (ele=="..")) 
                st.pop();
            else if(ele!="." && ele!="" && ele!="..") 
                st.push(ele);
        }
        if(st.empty()) return "/";
        string res="";
        while(st.size()>1){
            res="/"+st.top()+res;
            st.pop();
        } 
        return "/"+st.top()+res;
    }
};