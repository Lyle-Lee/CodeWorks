class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        frequency = collections.Counter()
        answer = []
        for word in words:
            mask = 0
            for ch in word:
                mask |= (1 << (ord(ch) - ord('a'))) # bit OR
            if str(bin(mask)).count('1') <= 7: # change to binary string; skip if num. of ch>7
                frequency[mask] += 1
        for puzzle in puzzles:
            total = 0
            mask = 0
            for i in range(1, 7):
                mask |= (1 << (ord(puzzle[i]) - ord('a')))
            subset = mask
            while subset:
                tmp = subset | (1 << (ord(puzzle[0]) - ord('a')))
                if tmp in frequency:
                    total += frequency[tmp]
                subset = (subset - 1) & mask # bit AND
            if (1 << (ord(puzzle[0]) - ord('a'))) in frequency: # check empty cases
                total += frequency[1 << (ord(puzzle[0]) - ord('a'))]
            answer.append(total)
        return answer
