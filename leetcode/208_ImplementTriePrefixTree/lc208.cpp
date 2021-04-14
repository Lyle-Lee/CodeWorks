class Trie {
private:
    Trie* next[26];
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) next[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (!node->next[ch]) node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (!node->next[ch]) return false;
            node = node->next[ch];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch: prefix) {
            ch -= 'a';
            if (!node->next[ch]) return false;
            node = node->next[ch];
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
