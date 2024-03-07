[Problem]<br>
https://leetcode.com/problems/single-number


[Answer 1]
```java
class Solution {
    public static int singleNumber(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0 ; i < nums.length ; i++){
            if(arr.contains(nums[i]) && arr.size() > 0){
                arr.remove((Object)nums[i]);
            }
            else{
                arr.add(nums[i]);
            }
        }
        return arr.get(0);
    }
}
```

[Answer 2]
```java
class Solution {
    public static int singleNumber(int[] nums) {
        int result = 0;
        for(int i = 0 ; i < nums.length ; i++){
            result = result^nums[i];
        }
        return result;
    }
}
```
