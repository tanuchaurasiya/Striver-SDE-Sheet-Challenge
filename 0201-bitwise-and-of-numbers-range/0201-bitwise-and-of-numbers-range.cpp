class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c=0;
        while(left!=right){
            left=left/2;
            right=right/2;
            c++;
        }
        while(c){
            left*=2;
            c--;
        }
        return left;
    }
};