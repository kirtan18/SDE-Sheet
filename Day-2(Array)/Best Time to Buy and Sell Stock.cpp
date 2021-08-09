https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

T.C = O(N)
S.C = O(1)  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxPrice = 0;
        
        for(int i = 0 ; i < prices.size(); i++){
            
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            
            if(prices[i] - minPrice > maxPrice){
                maxPrice = prices[i] - minPrice;
            }
        }
       return maxPrice; 
    }
};
