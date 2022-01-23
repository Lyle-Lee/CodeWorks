class StockPrice {
private:
    unordered_map<int, int> mp;
    map<int, int> priceCnt;
    int curTime;

public:
    StockPrice(): curTime(0) {}
    
    void update(int timestamp, int price) {
        int previousPrice = mp.count(timestamp) ? mp[timestamp] : 0;
        mp[timestamp] = price;
        curTime = max(curTime, timestamp);
        ++priceCnt[price];
        if (previousPrice > 0) {
            --priceCnt[previousPrice];
            if (priceCnt[previousPrice] == 0) priceCnt.erase(previousPrice);
        }
    }
    
    int current() {
        return mp[curTime];
    }
    
    int maximum() {
        return (*priceCnt.rbegin()).first;
    }
    
    int minimum() {
        return (*priceCnt.begin()).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
