A = int(input())
B = int(input())
C = int(input())
X = int(input())

counter = 0
Res = X

N_maxA = X / A

for i in range(N_maxA + 1):
	Res = X - (i * 500)
	N_maxB = Res / B
	for j in range(N_maxB + 1):
		counter += 1

print(counter)

		

