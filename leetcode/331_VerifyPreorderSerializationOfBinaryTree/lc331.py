class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        l = preorder.split(',')
        children = []
        for i in range(len(l)):
            if l[i] == '#':
                children.append(0)
            else:
                children.append(2)
            for j in range(i):
                if children[i-1-j] > 0:
                    children[i-1-j] -= 1
                    break
                if j == i-1:
                    return False
        if sum(children) > 0:
            return False
        else:
            return True
