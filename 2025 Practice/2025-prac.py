class Solution(object):
    def strStr(self, haystack, needle):
        return haystack.find(needle)  # 파이썬 내장 함수 사용

sol = Solution()
result = sol.strStr('aasadbutsad','sad')
print(result)