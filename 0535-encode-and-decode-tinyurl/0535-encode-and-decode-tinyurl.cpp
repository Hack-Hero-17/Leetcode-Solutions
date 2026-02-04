class Solution {
public:

    unordered_map<string,string> umap;
    int id = 0 ;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        string code = to_string(id++);
        umap[code] = longUrl;
        return ( "http://shorten/" + code );    
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        string lastDigit = shortUrl.substr(shortUrl.find_last_of('/') + 1) ;
        return umap[lastDigit];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));