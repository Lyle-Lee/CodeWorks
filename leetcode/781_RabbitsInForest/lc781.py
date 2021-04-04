class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        n = len(answers)
        if n == 0:
            return 0
        len_count = max(answers) + 1
        count = [0 for x in range(len_count)]
        for i in range(n):
            count[answers[i]] += 1
        result = count[0]
        for i in range(1, len_count):
            if count[i] > 0:
                if count[i] % (i + 1) == 0: # all member from the color group have told the number
                    result += (i + 1) * (count[i] // (i + 1))
                else: # have space to count as the same color
                    result += (i + 1) * (count[i] // (i + 1)) + (i + 1)
        return result
