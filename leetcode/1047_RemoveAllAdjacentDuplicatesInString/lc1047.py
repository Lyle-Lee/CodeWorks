class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        for ch in S:
            if stack and stack[-1] == ch:
                stack.pop()
            else:
                stack.append(ch)
        return ''.join(stack)
        #top = 0
        #for ch in S:
        #    if top == 0 or S[top-1] != ch:
        #        S = S[:top] + ch + S[top+1:]
        #        top += 1
        #    else:
        #        top -= 1
        #return S[:top]
