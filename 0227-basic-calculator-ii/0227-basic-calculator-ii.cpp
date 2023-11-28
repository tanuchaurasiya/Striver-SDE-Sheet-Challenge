class Solution {
public:
    int calculate(string s) {
        int lastNum=0;
        char lastSign = '+';
        int res=0;
        int i=0;
    
        while(i<s.length()){
            if(s[i]==' '){
                i++;
                continue;
            }
            else if(isdigit(s[i])){
                string dig="";
                while(isdigit(s[i])){
                    dig+=s[i];
                    i++;
                }
                int n = stoi(dig);
                if(lastSign=='+') {
                    res+=n;
                    lastNum=n;
                }
                
                if(lastSign=='-') {
                    res-=n;
                    lastNum=-n;
                }
                
                if(lastSign=='*') {
                    res-=lastNum;
                    res+=lastNum*n;
                    lastNum=lastNum*n;
                }
                if(lastSign=='/') {
                    res-=lastNum;
                    res+=lastNum/n;
                    lastNum=lastNum/n;
                }
            
            }
            
            else{
                lastSign=s[i];
                i++;
            }
        }
        return res;
    }
};