import re
SIZE = 10

station=[[]for _ in range(SIZE)]
people=[]
for _ in range(SIZE):
    # 각 줄에서 두 개의 숫자를 입력받음
    x, y = map(int, input().split())
    people.append([x, y])  # 튜플로 저장
people_list=list(people)
for i in range(0,SIZE):
    for j in range(0,2):
        station[i].append(people_list[i][j])
# print(station)
max = 0
train = 0
for i in range(len(station)):
    train = train - station[i][0]
    train = train + station[i][1]
    if max < train :
        max = train
print(max)