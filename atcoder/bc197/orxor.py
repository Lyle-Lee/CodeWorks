def orxor(A, N):
  num_ops = 1 << (N - 1) # total num of possible or / xor operations
  ans = float('inf') # use a relatively large number
  for bit in range(num_ops):
    xor = 0
    cur = A[0]
    for i in range(N - 1):
      if bit >> i & 1: # cut (xor operation) while current bit is 1
        xor ^= cur
        cur = A[i+1]
      else:
        cur |= A[i+1]
    xor ^= cur
    ans = min(ans, xor)
  return ans

n = int(input())
l = list(map(int, input().split()))
print(orxor(l, n))
