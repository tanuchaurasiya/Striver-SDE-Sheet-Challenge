// Watch neetcode vdo
class Solution {
public:
    string longestPalindrome(string s) { 
        int res=0;
        string op;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            int l = i;
            int r = i;
            string x ="";
            while(l>=0 && r<=n-1 && s[l]==s[r]){  
                if (res<r-l+1){
                    res=r-l+1; 
                    for(int j=l;j<=r;j++)
                       x+=s[j];
                    op = x;  
                    x="";
                } 
            
                l-=1;
                r+=1;
            } 
            
            cout<<"x="<<x<<endl;
            l = i;
            r = i+1;
           
            
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if (res<r-l+1){
                    res=r-l+1; 
                    for(int j=l;j<=r;j++)
                       x+=s[j];
                    op = x;
                    x="";
                } 
                l-=1;
                r+=1;
            } 
            
            cout<<"xq="<<x<<endl;
            
        }
        return op;
    }
};