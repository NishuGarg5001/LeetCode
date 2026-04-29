class Solution:
    def isPalindrome(self, s, l):
        for i in range(l//2):
            if s[i] != s[l - 1 - i]:
                return False
        return True

    def longestPalindrome(self, s):
        if len(set(s)) == 1:
            return s
        length = len(s)
        result = ""
        for i in range(length):
            for j in range(i, length):
                substring = s[i:j + 1]
                l = len(substring)
                if self.isPalindrome(substring, l) and l > len(result):
                    result = substring
        return result

print(Solution().longestPalindrome("hello"))
print(Solution().longestPalindrome("firefightahtenetdestroy"))
print(Solution().longestPalindrome("racecar-redrum-nitin"))