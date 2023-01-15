class StockPrice {
public:
    StockPrice() {
        
    }
    unordered_map<int,int>map;
    multiset<int> prices;
    int currTime = 0;
    void update(int timestamp, int price) {
        if(map.find(timestamp) != map.end()){
            prices.erase(prices.find(map[timestamp]));
        }
        map[timestamp] = price;
        prices.insert(price);
        currTime = max(currTime, timestamp);
    }
    
    int current() {
        return map[currTime]; 
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
           return *prices.begin();     
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
