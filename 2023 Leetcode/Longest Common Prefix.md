[Problem]<br>
https://leetcode.com/problems/longest-common-prefix/


[Answer 1]
```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        ArrayList<String> words = new ArrayList<>();
        ArrayList<String> sorted = new ArrayList<>();
        for(int i = 0 ; i < strs.length ; i++){
            sorted.add(strs[i]);
        }
        Collections.sort(sorted, Comparator.comparing(String::length));
        int maxLength = 0;
        for(int j = 1 ; j < sorted.get(0).length()+1 ; j++){
                String newWord = sorted.get(0).substring(0, j);
                if(isContains(newWord, sorted) == true){
                    words.add(newWord);
                    if(maxLength < newWord.length()){
                        maxLength = newWord.length();
                    }
                }
            }
        if(words.size() == 0){
            return "";
        }else{
            Collections.sort(words, Comparator.comparing(String::length));
            return words.get(words.size()-1);
        }
    }
    public boolean isContains(String word, ArrayList<String> strs){
        for(int i = 1 ; i < strs.size() ; i++){
            if(strs.get(i).startsWith(word) == false){
                return false;
            }
        }
        return true;
    }
}
```

[Answer 2]
```java
class Solution {
    public String longestCommonPrefix(String[] v) {
        StringBuilder ans = new StringBuilder();
        Arrays.sort(v);
        String first = v[0];
        String last = v[v.length-1];
        for (int i=0; i<Math.min(first.length(), last.length()); i++) {
            if (first.charAt(i) != last.charAt(i)) {
                return ans.toString();
            }
            ans.append(first.charAt(i));
        }
        return ans.toString();
    }
}
```
