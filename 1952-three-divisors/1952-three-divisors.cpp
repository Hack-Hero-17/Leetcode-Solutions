class Solution {
public:
    bool isThree(int n) {
        int root = sqrt(n);
        if(root * root != n) return false;
        for(int i = 2; i * i <= root; ++i){
            if(root % i == 0) return false;
        }
        return root > 1;
    }
};