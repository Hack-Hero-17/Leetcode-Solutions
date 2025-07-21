class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int front = 0;
        int back = s.size() - 1;
        while(front < back){
            if(!vowels.contains(s[front]) && !vowels.contains(s[back])){
                front++;
                back--;
            }
            if(vowels.contains(s[front]) && vowels.contains(s[back])){
                char temp = s[front];
                s[front] = s[back];
                s[back] = temp;
                front++;
                back--;
            }
            else if(vowels.contains(s[front])){
                back--;
            }
            else if(vowels.contains(s[back])){
                front++;
            }
        }
        return s;
    }
};