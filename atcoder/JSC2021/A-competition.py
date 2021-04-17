def best_price(x, y, z):
  p = y / x * z
  p = int(p) - 1
  while p / z < y / x:
    p += 1
  return p - 1

X, Y, Z = map(int, input().split())
print(best_price(X, Y, Z))
