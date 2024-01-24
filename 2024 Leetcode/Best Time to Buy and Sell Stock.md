[Problem]<br>
https://leetcode.com/problems/best-time-to-buy-and-sell-stock

[Answer 1]
```java
class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int op = 0;
        int mp = 0;
        for(int i = 0 ; i < prices.length ; i++){
            if(prices[i] < min){
                min = prices[i];
            }
            mp = prices[i] - min;
            
            if(op < mp){
                op = mp;
            }
        }
        return op;
    }
}
```