A = int(input())
B = int(input())
C = int(input())
X = int(input())

counter = 0

N_maxA = min( int(X // 500), A )

for i in range(N_maxA + 1):
	Res = X - (i * 500)
	N_maxB = min( int(Res // 100) , B )
	
	for j in range(N_maxB + 1):
		Res1 = Res - j*100
		if int(Res1 // 50) <= C:
			
			counter += 1

print(counter)



