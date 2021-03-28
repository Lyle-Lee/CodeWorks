def find_visible(mat, h, w, x, y):
  left = y - 1
  right = y + 1
  top = x - 1
  bottom = x + 1
  while left > 0 and mat[x-1][left-1] != '#':
    left -= 1
  while right <= w and mat[x-1][right-1] != '#':
    right += 1
  while top > 0 and mat[top-1][y-1] != '#':
    top -= 1
  while bottom <= h and mat[bottom-1][y-1] != '#':
    bottom += 1
  return right - left - 2 + bottom - top - 2 + 1

h, w, x, y = map(int, input().split())
mat = [input() for x in range(h)]
print(find_visible(mat, h, w, x, y))
