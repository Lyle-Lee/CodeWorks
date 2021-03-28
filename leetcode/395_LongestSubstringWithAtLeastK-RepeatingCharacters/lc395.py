class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if not s:
            return 0
        frequency = collections.Counter()
        for ch in s:
            frequency[ord(ch)] += 1
        for ch in s:
            if frequency[ord(ch)] < k:
                return max(self.longestSubstring(substring, k) for substring in s.split(ch))
        return len(s)
