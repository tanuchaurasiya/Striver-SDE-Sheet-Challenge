class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        mx_profit = 0
    
        for i in range(1,len(prices)):
            profit = prices[i]-buy 
            # print(profit)
            if profit>mx_profit:
                mx_profit = profit
            # print(mx_profit)
            if buy>prices[i]:
                buy = prices[i] 
                # print("buy",buy)
    
        return mx_profit