[Problem]<br>
https://leetcode.com/problems/jump-game-ii/description

```java
class Solution {
    public int jump(int[] nums) {
        int jumps=0, current_end=0, farthest=0;
        for(int i = 0 ; i < nums.length-1 ; i++){
            farthest = Math.max(farthest, i+nums[i]);
            //제일 먼곳까지 점프했다면? ->
            //jump수 추가 ->
            //다시 제일 먼곳 까지 점프할 수 있는곳 지정 ->
            //반복
            if(i == current_end){
                jumps++;
                current_end = farthest;
            }
        }
        return jumps;
    }
}
```

```python
class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps=0
        current_end=0
        farthest=0
        for i in range(len(nums)-1):
            farthest = max(farthest, i+nums[i])
            if i == current_end:
                jumps+=1
                current_end = farthest

        return jumps
```