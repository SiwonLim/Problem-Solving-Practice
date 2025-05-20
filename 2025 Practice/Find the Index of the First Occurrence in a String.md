[Problem]<br>
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

```python
class Solution(object):
    def strStr(self, haystack, needle):
        return haystack.find(needle)

sol = Solution()
result = sol.strStr('aasadbutsad','sad')
print(result)
```