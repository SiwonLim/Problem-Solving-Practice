[Problem]<br>
https://leetcode.com/problems/pascals-triangle


[Answer 1] : Java
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> out = new ArrayList<>();
        for(int i = 0 ; i < numRows ; i++){
            List<Integer> in = new ArrayList<>();
            if(i < 2){
                for(int j = 0 ; j <= i ; j++){
                    in.add(1);
                }
            }else{
                for(int j = 0 ; j < i-1 ; j++){
                    in.add(out.get(i-1).get(j) + out.get(i-1).get(j+1));
                }
                in.add(0, 1);
                in.add(in.size(),1);
            }
            out.add(in);
        }
        return out;
    }
}
```

[Answer 2] : Java
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> l = new ArrayList<>();
        for (int i = 0; i < numRows; i++) 
        {
            int[] dp = new int[i + 1];
            dp[0] = 1;
            dp[dp.length - 1] = 1;
            for (int j = 1; j < dp.length - 1; j++) 
            {
                dp[j] = l.get(i - 1).get(j - 1) + l.get(i - 1).get(j);
            }
            List<Integer> rowList = new ArrayList<>();
            for (int num : dp) {
                rowList.add(num);
            }
            l.add(rowList);
        }
        return l;
    }
}
```

[Answer 3] : Python
```python
class Solution(object):
    def generate(self, numRows):
        result = []
        if numRows == 0:
            return result
        first_row = [1]
        result.append(first_row)

        for i in range(1, numRows):
            prev_row = result[i-1]
            current_row = [1]

            for j in range(1,i):
                current_row.append(prev_row[j-1]+prev_row[j])
            
            current_row.append(1)
            result.append(current_row)
        return result
```
