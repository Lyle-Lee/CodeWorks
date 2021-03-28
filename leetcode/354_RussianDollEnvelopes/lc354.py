class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if not envelopes:
            return 0
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        answer_min_h = [envelopes[0][1]] # last index is answer
        for i in range(1, len(envelopes)):
            if answer_min_h[-1] < envelopes[i][1]:
                answer_min_h.append(envelopes[i][1])
            else:
                index = bisect.bisect_left(answer_min_h, envelopes[i][1]) # necessary for the last one
                answer_min_h[index] = envelopes[i][1]
        return len(answer_min_h)
