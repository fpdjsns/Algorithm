/**
 * problem : https://leetcode.com/problems/online-stock-span/
 * space complexity : O(N)
 * time complexity : O(1)
 * 참고 : https://leetcode.com/problems/online-stock-span/solutions/2643474/online-stock-span/
 */

class StockSpanner {
    vector<pair<int,int>> arr; // val, maxInd
public:
    StockSpanner() {
        arr = vector<pair<int,int>>();
    }
    
    int next(int price) {
        int ind = arr.size()-1;
        while(ind >= 0 && arr[ind].first <= price) {
            ind = arr[ind].second;
        }
        int ans = arr.size() - ind;
        arr.push_back({price, arr.size() - ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
