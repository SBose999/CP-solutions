"""
    author - Sayan Bose
    link - https://codeforces.com/problemset/problem/225/A
    source - CodeForces
    Sample Input : 
    3
    6
    3 2
    5 4
    2 4
    Sample Output :
    YES
"""

def solve():
    n = int(input())
    top = int(input())
    li = []
    for _ in range(n):
        li.append(list(map(int, input().split())))
    t1 = [abs(top-7)]
    t = []
    for i in li:
        temp = [i[0], abs(i[0] - 7), i[1], abs(i[1] - 7)]
        for j in range(1, 7):
            if j not in temp:
                t.append(j)
        r = []
        for j in t:
            if j not in t1:
                r.append(j)
        t = []
        t1 = []
        for j in r:
            t1.append(j)
        if not r or len(r)>1:
            print('NO')
            exit()
    print('YES')
if __name__ == "__main__":
    solve()