class TrieNode {

    public:

    TrieNode* arr[26];
    bool isEnd;

    TrieNode() {

        for(int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }

        isEnd = false;
    }
};


class Trie {

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        int len = word.length();
        TrieNode* node = root;
        for(int i = 0; i < len; i++) {

            if(node->arr[word[i] - 'a'] == nullptr) {
                node->arr[word[i] - 'a'] = new TrieNode();
            }

            node = node->arr[word[i] - 'a'];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        
        int len = word.length();
        TrieNode* node = root;
        for(int i = 0; i < len; i++) {

            if(node->arr[word[i] - 'a'] == nullptr) {
                return false;
            }

            node = node->arr[word[i] - 'a'];
        }

        return (node->isEnd == true);
    }
    
    bool startsWith(string prefix) {

        int len = prefix.length();
        TrieNode* node = root;
        for(int i = 0; i < len; i++) {

            if(node->arr[prefix[i] - 'a'] == nullptr) {
                return false;
            }

            node = node->arr[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */