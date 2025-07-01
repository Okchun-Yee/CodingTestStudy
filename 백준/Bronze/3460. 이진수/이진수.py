t=int(input())
n=[]
for i in range(t):
    n.append(int(input()))
bin=[[]for _ in range(t)]

result=[]
for i in range(0,t):
    while(n[i]>=1):
        bin[i].append(int(n[i]%2))
        n[i]=int(n[i]/2)
    cnt = 0
    for _ in bin[i]:
        if bin[i][cnt]==1:
            result.append(cnt)
        cnt+=1
    print(" ".join(str(i) for i in result))
    result.clear()
        