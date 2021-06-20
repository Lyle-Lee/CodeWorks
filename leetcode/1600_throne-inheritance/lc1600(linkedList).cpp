struct Node {
    string name;
    Node* next = nullptr;
    Node* last = nullptr; // the last child of current chain
    bool isAlive = true;
    Node() {}
    Node(string x): name{x} {}
};

class ThroneInheritance {
private:
    unordered_map<string, Node*> map;
    Node* root = new Node();

public:
    ThroneInheritance(string kingName) {
        root->name = kingName;
        map[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* child = new Node(childName);
        map[childName] = child;
        Node* parent = map[parentName];
        Node* tmp = parent;
        while (tmp->last != nullptr) tmp = tmp->last;
        child->next = tmp->next;
        tmp->next = child;
        parent->last = child;
    }
    
    void death(string name) {
        map[name]->isAlive = false;
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        Node* tmp = root;
        while (tmp != nullptr) {
            if (tmp->isAlive) ans.push_back(tmp->name);
            tmp = tmp->next;
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
