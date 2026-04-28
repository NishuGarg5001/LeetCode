class Solution:
    def lengthOfLongestSubstring(self, s):
        last_seen = [-1]*256
        start = result_len = 0

        for i in range(len(s)):
            if last_seen[ord(s[i])] >= start:
                start = last_seen[ord(s[i])] + 1

            last_seen[ord(s[i])] = i

            length = i - start + 1
            if length > result_len:
                result_len = length

        return result_len


s1 = "abcabcbb"
s2 = "haggleeeeeeeewarfonttttt"
print(s1)
print(Solution().lengthOfLongestSubstring(s1))
print(s2)
print(Solution().lengthOfLongestSubstring(s2))