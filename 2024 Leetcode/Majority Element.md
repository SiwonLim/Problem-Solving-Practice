[Problem]<br>
https://leetcode.com/problems/majority-element


[Answer 1]
```java
class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0 ; i < nums.length ; i++){
            if(map.containsKey(nums[i])==true){
                int v = map.get(nums[i]);
                map.replace(nums[i],v+1);
            }else{
                map.put(nums[i], 1);
            }
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort(Map.Entry.comparingByValue());
        return list.get(list.size()-1).getKey();
    }
}
```
