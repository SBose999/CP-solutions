"""
author - Sayan Bose
link - https://codeforces.com/problemset/problem/460/B
source - CodeForces
Sample Input:
2 2 -1
Sample Output:
4
1 31 337 967 
"""
def sum_num(a):
	s = 0
	a = abs(a)
	while a:
		s += a % 10
		a //= 10
	return s

a, b, c = map(int, input().split())
res = []
for i in range(1, 82):
	if sum_num(b*(i**a)+c) == i and b*(i**a)+c > 0 and b*(i**a)+c <1e9:
		res.append(b*(i**a) + c)
print(len(res))
print(*res)