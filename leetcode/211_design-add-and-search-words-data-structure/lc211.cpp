struct Trie {
    bool isEnd = false;
    unordered_map<char, Trie*> next;
};

class WordDictionary {
private:
    Trie* root;
    bool dfs(string word, int startIdx, Trie* node) {
        if (startIdx == word.size()) return node->isEnd;
        char ch = word[startIdx];
        if (ch != '.') {
            if (!node->next.count(ch)) return false;
            return dfs(word, startIdx + 1, node->next[ch]);
        } else {
            for (auto& [nextCh, _]: node->next) {
                if (dfs(word, startIdx + 1, node->next[nextCh])) return true;
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* cur = root;
        for (char& ch: word) {
            if (!cur->next.count(ch)) cur->next[ch] = new Trie();
            cur = cur->next[ch];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
