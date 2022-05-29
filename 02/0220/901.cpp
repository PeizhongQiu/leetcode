class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        priceArray.push_back(price);
        int sum = 1;
        if(!nextArray.empty()) {
            int index = nextArray.size() - 1;
            
            while(index >= 0) {
                if(priceArray[index] > price) {
                    break;
                } else {
                    sum += nextArray[index];
                    index -= nextArray[index];
                }
            }
            
        }
        nextArray.push_back(sum);
        return sum;
    }
private:
    vector<int> nextArray;
    vector<int> priceArray;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
