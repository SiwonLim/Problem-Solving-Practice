[Problem]<br>
https://leetcode.com/problems/merge-sorted-array


[Answer 1]
```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0 ; i < m ; i++){
            arr.add(nums1[i]);
        }
        for(int i = 0 ; i < n ; i++){
            arr.add(nums2[i]);
        }
        Collections.sort(arr);
        for(int i = 0 ; i < arr.size() ; i++){
            nums1[i] = arr.get(i);
        }
    }
}
```
