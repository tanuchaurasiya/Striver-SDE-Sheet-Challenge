class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int n= s.length(); 
        int res= 0;
        // cout<<n;
        while(i<n){
            int j=i+1;
            unordered_set<char> st; 
            st.insert(s[i]); 
            
            while(j<n){
                if(st.find(s[j])==st.end()) { 
                    st.insert(s[j]); 
                    j+=1;
                }
                else{
                    res=max(res, j-i);
                    break;
                }
            }
            
            
            res=max(res,j-i);
            i+=1;
        }
        return res;
    }
        
};