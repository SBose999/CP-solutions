"""
author - Sayan Bose
link - https://codeforces.com/problemset/problem/272/C
source - CodeForces
Sample input : 
5
1 2 3 6 6
4
1 1
3 1
1 1
4 3
Sample Output:
1
3
4
6
"""
from sys import stdin


def ip():
    return stdin.readline().split()


if __name__ == "__main__":
    n = int(stdin.readline())
    li = list(map(int, ip()))
    m = int(stdin.readline())
    for _ in range(m):
        w, h = map(int, ip())
        print(max(li[0], li[w-1]))
        li[0] = max(li[0], li[w-1]) + h