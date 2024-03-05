class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        int n = s.length();
        int ans=n;
        while(i<j){
            
            if(s[i]!=s[j]) { 
                return ans;
            }
            ans-=2;
            while(i+1<j && i+1<n && s[i]==s[i+1]){
                ans--;
                i++;
            }
            while(i+1<j && j-1<n && s[j]==s[j-1]){
                ans--;
                j--;
            }
            
            
            i++;
            j--;
            
        } 
        
        return ans;
    }
};