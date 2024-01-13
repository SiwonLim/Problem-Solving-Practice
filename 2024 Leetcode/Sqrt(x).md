[Problem]<br>
https://leetcode.com/problems/sqrtx


[Answer 1 : Java]
```java
class Solution {
    public int mySqrt(int x) {
         if(x < 0){
            return -1;
        }
        int low = 1, high = x, res = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mid <= (x/mid)){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
}
```

[Answer 2 : Python]
```python
class Solution(object):
    def mySqrt(self, x):
        if x < 0:
            return -1
        low=1
        high=x
        res=0
        while low <= high:
            mid = low + (high-low)/2
            if mid <= x/mid:
                res = mid
                low = mid+1
            else:
                high = mid-1
        return res
```
