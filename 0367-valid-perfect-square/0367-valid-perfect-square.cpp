class Solution {
public:
    bool isPerfectSquare(int num) {
        // if(num==0) return true;
        int x = 1;
        while(num>0){
            num-=x;
            x+=2;
        }
        return num==0;
    }
};