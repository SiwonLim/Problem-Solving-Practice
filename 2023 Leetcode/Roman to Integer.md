[Problem]<br>
https://leetcode.com/problems/roman-to-integer/

[Answer 1]
```java
import java.util.HashMap;
class Solution {
    public int romanToInt(String s) {
        HashMap<String, Integer> romanSet = new HashMap<String, Integer>();
        HashMap<String, Integer> romans = new HashMap<String, Integer>();

        romanSet.put("IV", 4);
        romanSet.put("XL", 40);
        romanSet.put("CD", 400);
        romanSet.put("IX", 9);
        romanSet.put("XC", 90);
        romanSet.put("CM", 900);

        romans.put("I", 1);
        romans.put("V", 5);
        romans.put("X", 10);
        romans.put("L", 50);
        romans.put("C", 100);
        romans.put("D", 500);
        romans.put("M", 1000);
        
        int result = 0;
        while(s.length() > 0){
            if(s.length() == 1){
                result += romans.get(String.valueOf(s.charAt(0)));
                return result;
            }else{
                String r = String.valueOf(s.charAt(0))+String.valueOf(s.charAt(1));
                if(romanSet.containsKey(r)){
                    result += romanSet.get(r);
                    s = s.substring(2, s.length());
                }else{
                    result += romans.get(String.valueOf(s.charAt(0)));
                    s = s.substring(1, s.length());
                }
            }
        }
        return result;
    }
}
```

[Answer 2]
```java
class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> m = new HashMap<>();
        
        m.put('I', 1);
        m.put('V', 5);
        m.put('X', 10);
        m.put('L', 50);
        m.put('C', 100);
        m.put('D', 500);
        m.put('M', 1000);
        
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                ans -= m.get(s.charAt(i));
            } else {
                ans += m.get(s.charAt(i));
            }
        }
        
        return ans;
    }
}
```
