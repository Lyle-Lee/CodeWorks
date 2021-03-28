class Solution:
    def countBits(self, num: int) -> List[int]:
        if num < 0:
            return None
        else:
            answer = [0]
            if num > 0:
                for i in range(1, num+1):
                    if i%2 == 0:
                        answer.append(answer[i//2])
                    else:
                        answer.append(answer[i//2] + 1)
            return answer
