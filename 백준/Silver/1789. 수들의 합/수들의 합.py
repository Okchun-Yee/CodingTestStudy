S = int(input())
if S == 1:
    print(1)
    exit(0)

sum =0
for cnt in range(1,S):
    sum += cnt
    if sum+cnt >= S:
        break
print(cnt)