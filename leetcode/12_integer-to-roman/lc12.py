class Solution:
    def intToRoman(self, num: int) -> str:
        token = [['CM', 'XC', 'IX'],
                 ['D', 'L', 'V'],
                 ['C', 'X', 'I'],
                 ['CD', 'XL', 'IV']]
        res = ''
        cur1, s1, cur2, s2, s3 = 1000, 900, 500, 400, 100
        res += 'M' * (num // cur1)
        for i in range(3):
            if num % cur1 >= s1:
                res += token[0][i]
            elif num % cur1 >= cur2:
                res += token[1][i] + token[2][i] * (num % cur2 // s3)
            elif num % cur1 >= s2:
                res += token[3][i]
            else:
                res += token[2][i] * (num % cur2 // s3)
            cur1, s1, cur2, s2, s3 = cur1 // 10, s1 // 10, cur2 // 10, s2 // 10, s3 // 10
        return res
