1
N = int(input())

a = input().split()

A = [int(s) for s in a]   #strのリストをintのリストに変換


Time = 0
i = 0


while i < N:
	if A[i] % 2 == 0:
		i += 1

		if i == N:
			for j in range(N):
				A[j] = A[j] / 2
			
			Time += 1
			i = 0

	elif A[i] % 2 == 1:
		break

	
	

print(Time)


	

#コメントアウトショートカットは command + /

