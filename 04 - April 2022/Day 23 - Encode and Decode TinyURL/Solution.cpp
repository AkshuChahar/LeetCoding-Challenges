class Solution {
public:
    // Initialise a map to keep track of short and long URLs.
    unordered_map<string, string> m;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // Initialise a string to store the short url.
        string res = "http://tinyurl.com/";
        // Now we add a random character to the short url.
        res.push_back((rand() % 127) + '0');
        // Now we check if the current short url already exists.
        // If it does, we keep adding a random character at the end untill we get an unique url.
        while (m.find(res) != m.end())
            res.push_back((rand() % 127) + '0');
        // Add the short url to the map with the corresponding long url.
        m[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));