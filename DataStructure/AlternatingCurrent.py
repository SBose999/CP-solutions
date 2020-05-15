"""
author - Sayan Bose
link - https://codeforces.com/contest/343/problem/B
source - CodeForces
"""

s = input()
stack = []
for i in s:
    if not stack:
        stack.append(i)
        continue
    f = 0
    while stack:
        if stack[-1] == i:
            f = 1
            stack.pop()
        else:
            break
    if not f:
        stack.append(i)
if stack:
    print('No')
else:
    print('Yes')