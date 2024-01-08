[Problem]<br>
https://leetcode.com/problems/valid-parentheses/description


[Answer 1]
```java
public boolean isValid(String s) {
    Stack<Character> stack = new Stack<>();
    for(int i = 0 ; i < s.length() ; i++){
        Character c = s.charAt(i);
        if(c == '(' || c == '{' || c == '['){
            stack.push(c);
        }else{
            if(stack.size() == 0){
                return false;
            }else{
                Character prev = stack.pop();
                if(prev == '(' && c == ')'){
                    continue;
                }else if(prev == '[' && c == ']'){
                    continue;
                }else if(prev == '{' && c == '}'){
                    continue;
                }else{
                    return false;
                }
            }
        }
    }
    return stack.isEmpty();
}
```

[Answer 2]
```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>(); // create an empty stack
        for (char c : s.toCharArray()) {
            if (c == '(')
                stack.push(')');
            else if (c == '{')
                stack.push('}');
            else if (c == '[')
                stack.push(']');
            else if (stack.isEmpty() || stack.pop() != c)
                return false;
        }
        return stack.isEmpty();
    }
}
```
