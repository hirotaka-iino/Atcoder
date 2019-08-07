N, A, B = (int(i) for i in input().split())



Sum = 0

for i in range(1, N + 1):
	Y = i
	Judge = 0

	while Y >= 1:
		Judge += Y % 10	#10で割った余り、512の場合は2、2の場合は2
		Y = int(Y // 10)	#10で割った商、512の場合は51、2の場合は0
		

	if A <= Judge and Judge <= B:
		Sum += i


print(Sum)



