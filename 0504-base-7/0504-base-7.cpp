class Solution {
public:
    string convertToBase7(int num)
    {
        //time complexity: O(logn)
        //space complexity: O(logn)

        //if given number(num) is 0, then return string "0"
        if(num==0)
            return "0";

        //taking string 'ans' to store final value
        string ans="";
        //taking a 'boolean' variable to handle negative numbers
        bool isNeg=(num<0);

        //taking 'absolute value' of given number(num) to perform operations
        num=abs(num);
        while(num>0)
        {
            //take remainder(after dividing by 7) and add it to 'ans'
            ans= to_string(num%7) + ans;
            //update the 'num' for further calculations
            num=num/7;
        }    

        //if given number is negative, then return it with a '-' sign
        if(isNeg)
            return '-'+ans;
        //otherwise, return the original 'ans'
        else
            return ans;
    }
};