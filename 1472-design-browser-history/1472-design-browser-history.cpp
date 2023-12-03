class BrowserHistory {
public:
    vector<string> st;
    int pointer; 
    int length;
    BrowserHistory(string homepage) { 
        st.push_back(homepage); 
        pointer=1; 
        length=1;
    }
    
    void visit(string url) {  
        if(length>pointer){
            // cout<<length<<" "<<pointer<<endl;
            int c = length-pointer;
            int cn=c;
            while(c){
                st.pop_back();
                c--;
            }
            length=length-cn;
        }
        st.push_back(url);
        length++;
        pointer=length;
        
    }
    
    string back(int steps) { 
        if(pointer-steps<=0) {
            pointer=1;
            return st[0];
        }
        else{
            pointer-=steps;
            return st[pointer-1];
        }
        
        
    }
    
    string forward(int steps) {
        if(pointer+steps>length) {
            pointer=length;
            return st[length-1];
        }
        else{
            pointer+=steps;
            return st[pointer-1];
        }
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */