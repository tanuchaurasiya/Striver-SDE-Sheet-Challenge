struct node{
    node* arr[26];
    bool isend=false;
};
class MagicDictionary {
    
public: 
    node* root;
    MagicDictionary() { 
        root = new node();
        
    }
    
    void buildDict(vector<string> dictionary) { 
        for(auto word:dictionary){
            node* temp = root;
            for(int i=0;i<word.length();i++){
                int idx = int(word[i]) - 97; 
                if(temp->arr[idx]==NULL) 
                    temp->arr[idx] = new node();
                temp = temp->arr[idx];
            } 
            
            temp->isend=true;
        }
    }
    
    bool help(int index, string word, node* root, bool isreplaced){ 
       if(index>=word.length()){
           if(root->isend && isreplaced) return true;
           return false;
       }
       node* curr = root;
        int idx = word[index]-97; 
        bool res=false;
        for(int i=0;i<26;i++){
            if(curr->arr[i]){
                if(i==idx) {
                    res= help(index+1, word, curr->arr[i], isreplaced);
                }
                else if(isreplaced!=true){
                    res = help(index+1, word, curr->arr[i],  true);
                }
            } 
            if(res==true) return true;
        } 
        return false;
    }
    bool search(string word) { 
        node* temp = root; 
        return help(0, word, temp, false);
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */