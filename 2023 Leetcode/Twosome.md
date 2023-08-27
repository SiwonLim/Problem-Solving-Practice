[Problem]<br>
https://leetcode.com/problems/two-sum/solutions/3619262/3-method-s-c-java-python-beginner-friendly/


[Answer1] : Brute Force
```java
package Java;
public class prac_20230826 {
    public static void main(String[] args) throws Exception{
        int[] test = {2,7,11,15};
        System.out.println(twoSum(test, 9).toString());

    }

    public static int[] twoSum(int[] nums, int target) {
        int[] answer = {0,0};
        for(int i = 0 ; i < nums.length ; i++){
            for(int j = i+1 ; j < nums.length ; j++){
                if(nums[i] + nums[j] == target){
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
            }
        }
        return null;
    }
}

```

[Answer2] : One pass hash table
```java
public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> numMap = new HashMap<>();
        int n = nums.length;

        for(int i = 0 ; i < n ; i++){
           int complement = target - nums[i];
           if(numMap.containsKey(complement)){
               return new int[] {numMap.get(complement), i};
        }
        numMap.put(nums[i],i);
        }
       return new int[]{};
    }
```
