class Solution:
    def calculate(self, s: str) -> int:
        sig_stack = []
        num_stack = []
        for i in range(len(s)):
            if s[i].isspace():
                continue
            elif s[i].isdigit():
                if i == 0 or not s[i-1].isdigit():
                    num_stack.append(s[i])
                else:
                    num = num_stack.pop() + s[i]
                    num_stack.append(num)
            else:
                if s[i] != ')':
                    sig_stack.append(s[i])
                else:
                    cal = sig_stack.pop()
                    if cal != '(':
                        result = 0
                        while cal != '(':
                            num = num_stack.pop()
                            if cal == '+':
                                result += int(num)
                            elif cal == '-':
                                result -= int(num)
                            cal = sig_stack.pop()
                        num_stack.append(result + int(num_stack.pop())) # add the 1st num in brackets
        answer = 0
        while sig_stack:
            num = num_stack.pop()
            cal = sig_stack.pop()
            if cal == '+':
                answer += int(num)
            elif cal == '-':
                answer -= int(num)
        if num_stack:
            answer += int(num_stack.pop())
        if num_stack:
            print('invalid input')
            return 0
        return answer
