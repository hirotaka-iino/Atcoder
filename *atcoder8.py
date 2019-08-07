N = int(input())

Y = int(input())

N_A_max = Y // 10000
N_B_max = Y // 5000
N_C_max = Y // 1000

for i in range(N_A_max + 1):
	Res = Y - i * 10000
	
 