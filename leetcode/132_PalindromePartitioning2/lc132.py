class Solution:
    def center_extend(self, s: str, left: int, right: int, cut: list):
        n = len(s)
        while left >= 0 and right < n and s[left] == s[right]:
            cut[right] = min(cut[right], cut[left-1] + 1 if left > 0 else 0)
            left -= 1
            right += 1

    def minCut(self, s: str) -> int:
        if not s or s == s[::-1]: # check special case
            return 0
        n = len(s)
        cut = [x for x in range(n)]
        for i in range(n):
            self.center_extend(s, i, i, cut) # check odd case
            self.center_extend(s, i, i+1, cut) # check even case
        return cut[-1]
