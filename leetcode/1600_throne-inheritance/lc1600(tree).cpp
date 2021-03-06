class ThroneInheritance {
private:
    unordered_set<string> dead;
    unordered_map<string, vector<string>> family;
    string king;

public:
    ThroneInheritance(string kingName): king{kingName} {}
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    // void preOrder(string name, vector<string>& ans) {
    //     if (!dead.count(name)) ans.push_back(name);
    //     if (family.count(name)) {
    //         for (auto &cName: family[name]) {
    //             preOrder(cName, ans);
    //         }
    //     }
    // }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        // preOrder(king, ans);
        stack<string> stk;
        stk.push(king);
        while (!stk.empty()) {
            string tmp = stk.top();
            stk.pop();
            if (!dead.count(tmp)) ans.push_back(tmp);
            if (family.count(tmp)) {
                for (auto iter = family[tmp].rbegin(); iter != family[tmp].rend(); ++iter) {
                    stk.push(*iter);
                }
            }
        }
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
