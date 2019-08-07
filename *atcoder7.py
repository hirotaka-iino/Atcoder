N = int(input())
d = [input() for i in range(N)]

d.sort(reverse = True) #降順にソート
counter = 0

for i in range(N):
	if  i < N-1 and d[i] > d[i+1]:
		counter += 1
	elif i == N-1:
		counter += 1

print(counter)