class Solution {
public:
    int minRemoved(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(')');
                }
                else if(st.top()==')'){
                    st.push(')');
                }
                else if(st.top()=='('){
                    st.pop();
                }
            }
        }
        
        int invalid=st.size(); //minimum removals
        
        return invalid;
    }
    
    
    void helper(int minRemove, string s, vector<string> &res, set<string> &visited){
        if(minRemove==0){
            if(minRemoved(s)==0) res.push_back(s);
            return;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z') continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1); 
            string temp = left+right;
            if(visited.find(temp)==visited.end()){
                visited.insert(temp);
                helper(minRemove-1, temp, res, visited);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int minRemove = minRemoved(s); 
        set<string> visited;
        // cout<<"minRemove = "<<minRemove<<endl;
        helper(minRemove, s, res, visited);
        return res;
    }
    
};

// (()l(