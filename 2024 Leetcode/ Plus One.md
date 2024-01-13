[Problem]<br>
https://leetcode.com/problems/plus-one/description/


[Answer 1]
```java
class Solution {
    public int[] plusOne(int[] digits) {
        boolean plus = false;
        int cnt = digits.length;
        for(int i = digits.length-1 ; i >= 0 ; i--){
            int newVal = 0;
            if(i == digits.length-1 || plus == true){
                newVal = digits[i]+1;
            }else{
                newVal = digits[i];
            }
            digits[i] = newVal%10;
            if(newVal >= 10){
                plus = true;
            }else{
                plus = false;
            }
        }
        if(plus == true){
            cnt++;
        }        
        int[] result = new int[cnt];
        if(plus == true){
            result[0] = 1;
            for(int i = 1 ; i < cnt ; i++){
                result[i] = digits[i-1];
            }
            return result;
        }
        return digits;
    }
}
```

[Answer 2]
```java
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
```
