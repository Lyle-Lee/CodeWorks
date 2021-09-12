struct Trie {
    string serial;
    unordered_map<string, Trie*> children;
    Trie(): serial("") {}
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie *root = new Trie();
        for (auto& path: paths) {
            Trie *cur = root;
            for (auto& node: path) {
                if (!cur->children.count(node)) cur->children[node] = new Trie();
                cur = cur->children[node];
            }
        }
        unordered_map<string, int> freq;
        function<void(Trie*)> construct = [&](Trie* node) {
            if (node->children.empty()) return;
            vector<string> vec;
            for (auto& [folder, child]: node->children) {
                construct(child);
                vec.push_back(folder + "(" + child->serial + ")");
            }
            sort(vec.begin(), vec.end());
            for (auto& path: vec) {
                node->serial += path;
            }
            ++freq[node->serial];
        };
        construct(root);
        vector<vector<string>> ans;
        vector<string> searchPath;
        function<void(Trie*)> doDelete = [&](Trie* node) {
            if (freq[node->serial] > 1) return;
            if (!searchPath.empty()) ans.push_back(searchPath);
            for (auto& [folder, child]: node->children) {
                searchPath.push_back(folder);
                doDelete(child);
                searchPath.pop_back();
            }
        };
        doDelete(root);
        return ans;
    }
};
