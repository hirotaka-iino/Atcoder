N = int(input())

a = list(int(i) for i in input().split() )

a.sort() #リストaを昇順にソート

i = Alice = Bob = 0

while len(a) >= 1:
	if i % 2 == 0:
		Alice += a.pop(len(a)-1) #リストaの末尾の値を加えて、リストから削除
	elif i % 2 != 0:
		Bob += a.pop(len(a)-1) #リストaの末尾の値を加えて、リストから削除

	i += 1


print(Alice - Bob)

