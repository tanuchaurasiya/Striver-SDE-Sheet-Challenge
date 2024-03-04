class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
    int j=tokens.size()-1; 
    sort(tokens.begin(), tokens.end()); 
    int Score=0; 
    int MaxScore=0;
    if(tokens.size()==0 || tokens[0]>power) return 0;
    while(i<=j){
        if(power>=tokens[i]) 
        {
           power-=tokens[i]; 
           i++; 
           Score++;
        } 


        else if(Score>0){  
              power+=tokens[j]; 
              j--;
              Score--; 
        } 
        
        
        MaxScore=max(Score, MaxScore); 
    } 


    return MaxScore;

    }
};