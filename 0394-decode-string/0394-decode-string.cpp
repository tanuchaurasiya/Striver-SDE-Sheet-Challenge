class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int i=0;
        string res="";
        while(i<s.length()){
            if(s[i]==']'){
                string temp;
                while(st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                cout<<"temp = "<<temp<<endl;
                int num = 0;
                int x=0;
                while((!st.empty()) && (!(st.top()>= 97 && st.top()<=122)) && (st.top()!='[' )){
                    int n = st.top() - int('0'); 
                    cout<<"n="<<n<<endl;
                    if(x==0){
                        num=n;
                        x=1;
                    }
                    else{
                        x=x*10;
                        num=n*x + num;
                    }
                    
                    st.pop(); 
                }
                cout<<"num="<<num<<endl;
                if(!st.empty()) {
                    while(num){
                        for(auto i: temp) 
                            st.push(i);
                        num--;
                    }
                }
                else{
                    
                    while(num){
                        res+=temp;
                        num--;
                    }
                    cout<<"res="<<res<<endl;
                }
                
            }
            else{
                st.push(s[i]);
            }
            
            i++;
        } 
        string p="";
        while(!st.empty()){
            p=st.top()+p;
            st.pop();
        }
        res+=p;
        return res;
    }
};