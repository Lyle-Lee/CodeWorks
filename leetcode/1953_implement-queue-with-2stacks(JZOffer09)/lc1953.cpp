class CQueue {
private:
    stack<int> inStk, outStk;
    
public:
    CQueue() {}
    
    void appendTail(int value) {
        inStk.push(value);
    }
    
    int deleteHead() {
        if (outStk.empty()) {
            if (!inStk.empty()) {
                while (!inStk.empty()) {
                    outStk.push(inStk.top());
                    inStk.pop();
                }
            } else {
                return -1;
            }
        }
        int ret = outStk.top();
        outStk.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
