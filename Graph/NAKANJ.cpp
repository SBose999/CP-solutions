/*
author - Sayan Bose
link - https://www.spoj.com/problems/NAKANJ/
source - SPOJ
*/
#include<bits/stdc++.h>
using namespace std;

struct cell{
    char col; int row;
};

// Construct Graph
map<cell, vector<cell>> board;
bool operator <(const cell& l, const cell& r)
{
    if(l.col != r.col)
        return l.col < r.col;
    return l.row < r.row;
}

void initialize()
{
    for(int i = int('a'); i < int('a') + 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cell node{char(i), j};
            cell c1{}, c2{}, c3{}, c4{}, c5{}, c6{}, c7{}, c8{};
            bool f1 = 1, f2 = 1, f3 = 1, f4 = 1, f5 = 1, f6 = 1, f7 = 1, f8 = 1;
            if(j + 2 <= 8 and i + 1 < int('a') + 8)
            {
                c1.row = j + 2;
                c1.col = char(i + 1);
                f1 = 0;
            }
            if(j - 2 >= 1 and i + 1 < int('a') + 8)
            {
                c2.row = j - 2;
                c2.col = char(i + 1);
                f2 = 0;
            }
            if(j + 1 <= 8 and i + 2 < int('a') + 8)
            {
                c3.row = j + 1;
                c3.col = char(i + 2);
                f3 = 0;
            }
            if(j - 1 >= 1 and i + 2 < int('a') + 8) {
                c4.row = j - 1;
                c4.col = char(i + 2);
                f4 = 0;
            }
            if(j + 2 <= 8 and i - 1 >= int('a'))
            {
                c5.row = j + 2;
                c5.col = char(i - 1);
                f5 = 0;
            }
            if(j - 2 >= 1 and i - 1 >= int('a'))
            {
                c6.row = j - 2;
                c6.col = char(i - 1);
                f6 = 0;
            }
            if(j + 1 <= 8 and i - 2 >= int('a'))
            {
                c7.row = j + 1;
                c7.col = char(i - 2);
                f7 = 0;
            }
            if(j - 1 >= 1 and i - 2 >= int('a')){
                c8.row = j - 1;
                c8.col = char(i - 2);
                f8 = 0;
            }
            if(!f1)
                board[node].push_back(c1);
            if(!f2)
                board[node].push_back(c2);
            if(!f3)
                board[node].push_back(c3);
            if(!f4)
                board[node].push_back(c4);
            if(!f5)
                board[node].push_back(c5);
            if(!f6)
                board[node].push_back(c6);
            if(!f7)
                board[node].push_back(c7);
            if(!f8)
                board[node].push_back(c8);
        }
    }
}

void solve()
{
    cell ini{}, fin{};
    cin >> ini.col >> ini.row;
    cin >>  fin.col >> fin.row;
    // bfs
    int node_fin = (int(fin.col) - int('a') + 1) * fin.row;
    queue<cell> Q;
    map<cell, bool> visited;
    map<cell, int> dist;
    visited[ini] = true;
    Q.push(ini);
    while(!Q.empty())
    {
        cell t = Q.front();
        Q.pop();
        for(auto i: board[t])
        {
            if(visited[i]) continue;
            visited[i] = true;
            dist[i] = dist[t] + 1;
            Q.push(i);
        }
    }
    printf("%d\n", dist[fin]);

}
int main()
{
    int t;
    scanf("%d", &t);
    initialize();
    while(t--)
    {
        solve();
    }
    return 0;
}