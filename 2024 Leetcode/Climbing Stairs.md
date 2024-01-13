[Problem]<br>
https://leetcode.com/problems/climbing-stairs


[Answer 1 : Java]
```java
class Solution {
    public int climbStairs(int n) {
        if(n < 3){
            return n;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2 ; i < n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
}
```

[Answer 2 : Python]
```python
class Solution(object):
    def climbStairs(self, n):
        if n < 3:
            return n
        else:
            dp = [0] * n
            dp[0] = 1
            dp[1] = 2
            for i in range(2, n):
                dp[i] = dp[i-1] + dp[i-2]
            print(dp[n-1])
            return dp[n-1]
```
