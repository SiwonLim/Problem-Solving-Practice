[Problem]<br>
https://leetcode.com/problems/valid-palindrome


[Answer 1]
```java
class Solution {
    public boolean isPalindrome(String s) {
        s = replaceAll(s).toLowerCase();
        int i = 0, j = s.length()-1;
        while(i < j){
            if(i >= j){
                return true;
            }else if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public String replaceAll(String str){
        return str.replaceAll("[^a-zA-Z0-9]", "");
    }
}
```
