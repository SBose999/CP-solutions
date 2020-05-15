"""
 author - Sayan Bose
 link - https://codeforces.com/problemset/problem/313/B
 source - CodeForces
"""
from sys import stdin
s = stdin.readline().strip()
dp = [0 for i in range(len(s))]
for i in range(len(s) - 1):
	if s[i] == s[i+1]:
		dp[i] = 1
dps = [dp[0]] + [0 for i in range(len(s) - 1)]
for i in range(1, len(s)):
	dps[i] = dps[i-1] + dp[i]
for _ in range(int(stdin.readline())):
	l, r = map(int, stdin.readline().split())
	l -= 1 
	r -= 2
	if l == 0:
		print(dps[r])
	else:
		print(dps[r] - dps[l-1])