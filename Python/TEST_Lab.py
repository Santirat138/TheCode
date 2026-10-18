n = 5
for row in range(n):
    print(*[(row + col) % n + 1 for col in range(n)])