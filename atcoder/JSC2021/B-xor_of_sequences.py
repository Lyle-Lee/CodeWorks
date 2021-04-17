def XORseq(n, m, a, b):
  res = []
  while n > 0 or m > 0:
    if n == 0:
      res += b
      m = 0
    elif m == 0:
      res += a
      n = 0
    else:
      x, y = a[0], b[0]
      if x < y:
        res.append(x)
        a.pop(0)
        n -= 1
      elif x > y:
        res.append(y)
        b.pop(0)
        m -= 1
      else:
        a.pop(0)
        b.pop(0)
        n -= 1
        m -= 1
  return res

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
l = XORseq(N, M, A, B)
for i in range(len(l)):
  print(l[i], end=' ')
