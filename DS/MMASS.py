"""
author - Sayan Bose
link - https://www.spoj.com/problems/MMASS/
source - SPOJ
"""

m = {'H': 1, 'C': 12, 'O': 16}
num = ['2', '3', '4', '5', '6', '7', '8', '9']


def mass(s):
    r = 0
    for J in range(len(s)):
        if s[J] is None:
            continue
        try:
            if s[J + 1] in num:
                r += m[s[J]] * int(s[J + 1])
                s[J + 1] = None
            else:
                r += m[s[J]]
        except IndexError:
            r += m[s[J]]
    return r


composition = input().strip()

stack = []
i = 0
while i < len(composition):
    if composition[i] == ')':
        temp = []
        t1 = 0
        while stack:
            if stack[-1] == '(':
                stack.pop()
                break
            else:
                t2 = stack.pop()
                if type(t2) == int:
                    t1 += t2
                else:
                    temp.insert(0, t2)
        try:
            if composition[i + 1] in num:
                stack.append((mass(temp) + t1) * int(composition[i + 1]))
                i += 1
            else:
                stack.append(mass(temp) + t1)
        except:
            stack.append(mass(temp) + t1)
    else:
        stack.append(composition[i])
    i += 1
res = 0
temp = []
while stack:
    t = stack.pop()
    if type(t) == int:
        res += t
    else:
        temp.append(t)
res += mass(temp[::-1])
print(res)
