class WordDictionary {
    vector<WordDictionary*> words;  // Trie to store words.
    bool isEnd;                     // Boolean to check if its the end of a word.
public:
    WordDictionary():isEnd(false) {
        words = vector<WordDictionary*>(26, nullptr);
    }

    void addWord(string word) {
        WordDictionary* curr = this;
        for (char c:word) {
            if (curr->words[c-'a'] == nullptr)
                curr->words[c-'a'] = new WordDictionary(); // Create new node if does not exist.
            curr = curr->words[c-'a'];                    // If character is already present move to next node.
        }
        curr->isEnd = true;                               // Mark the end of the word.
    }

    bool search(string word) {
        WordDictionary* curr = this;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto w:curr->words) {
                    if (w && w->search(word.substr(i+1)))
                        return true;
                }
                return false;
            }

            if (curr->words[c-'a'] == nullptr)             // If character is not present at that node, return 'false'.
                return false;
            curr = curr->words[c-'a'];                     // Move to next character.
        }

        return curr && curr->isEnd;                        // Return 'true' if word is found.
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */