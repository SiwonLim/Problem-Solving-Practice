[Problem]<br>
https://leetcode.com/problems/remove-duplicates-from-sorted-array


[Answer 1]
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 1;
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i-1] != nums[i]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
}
```
