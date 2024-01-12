[Problem]<br>
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string


[Answer 1]
```java
class Solution {
    public int strStr(String haystack, String needle) {
        int pivot = haystack.indexOf(needle, 0);
        return pivot;
    }
}
```
