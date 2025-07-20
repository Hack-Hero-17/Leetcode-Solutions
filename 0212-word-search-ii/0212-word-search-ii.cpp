//creating a different structure of trie that have only children and an empty string called word = "" , only for the end of the string character we provide the particular word to it making its length more then 0 and also storing the answer so we dont need an isTerminal thing :)
class Solution {
    struct TrieNode{
        string word;
        TrieNode* children[26];

        TrieNode(){
            word = "";
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words); //create the trie for all words

        vector<string> result; //to stroe ans
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                dfs(board, i, j, root, result); //call the dfs for each index
            }
        }
        return result;
    }

    TrieNode* buildTrie(vector<string> &words){
        TrieNode* root = new TrieNode();
        for(int i=0; i<words.size(); i++){ //iterating over every word
            string w = words[i];
            TrieNode* curr = root; //starting from root each time with a refrence curr
            for(int j=0; j<w.size(); j++){ //iterating for the size of word
                int idx = w[j]-'a'; 
                if(curr->children[idx] == NULL){ //checking if that index is empty? if yes creat one and point curr there
                    curr->children[idx] = new TrieNode(); //note: dont think much every root creates a children[26] and each of them is null but then we go to a particular index and create a refrence to other children marking it not null with help us keep traveling and seprating it from others
                }
                curr = curr->children[idx];
            }

            curr->word = w;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* &root, vector<string> &result){
        char ch = board[i][j];
        if(ch == '#' || !root->children[ch-'a']) return;

        TrieNode* curr = root->children[ch-'a'];
        if(curr->word.length() > 0){
            result.push_back(curr->word); // we took word instead of isTerminal so that we can push that word into our result
            curr->word = ""; //not to enter duplicate;
        }

        board[i][j] = '#'; //mark it here so that its not permanent and you can change it back

        if((i-1)>=0) dfs(board, i-1, j, curr, result);
        if((i+1)<board.size()) dfs(board, i+1, j, curr, result);
        if((j-1)>=0) dfs(board, i, j-1, curr, result);
        if((j+1)<board[0].size()) dfs(board, i, j+1, curr, result);

        board[i][j] = ch;
    }
};