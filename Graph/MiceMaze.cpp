/*
 * author - Sayan Bose
 * link - https://www.spoj.com/problems/MICEMAZE/
 * source - SPOJ
 */

/*
Sample input :
4 
2 
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1
Sample Output :
3
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, exit, time, m;
    cin >> n >> exit >> time >> m;
    // Construct Graph
    vector<pair<int, int>> adj[n+1];
    while(m--){
        int s, e, t;
        cin >> s >> e >> t;
        adj[e].emplace_back(s, t);
    }
    // Djikstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, exit});
    bool processed[n+1];
    memset(processed, false, sizeof(processed));
    int distance[n+1];
    for(int i = 0; i <= n; i++) distance[i] = 1e7;
    distance[exit] = 0;
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto i : adj[a]){
            int b = i.first, w = i.second;
            if(distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }
    int c = 0;
    for(int i = 1; i <= n; i++)
    {
        // cout << distance[i] << ' ';
        if(distance[i] <= time)
            c++;
    }
    cout << c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}