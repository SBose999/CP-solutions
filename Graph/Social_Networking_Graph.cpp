/*
 * author - Sayan Bose
 * link - https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph
 * source - hackerearth
 */

/*
    Question : In a social networking site, personsple are connected with other people. The whole system appears as a giant connected graph. In this question, you are required to answer the total number of people connected at t nodes away from each other (t distance connectivity). For example: Two persons directly connected are at 1 distance connectivity. While the two persons having a common contact without having direct connectivity, are at 2 distance connectivity.
    First line of input line contains, two integers n and e, where n is the nodes and e are the edges. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. Next line contains single integer, m, which is number of queries. Next m lines, each have two inputs, one as source node and other as a required t distance connectivity which should be used to process query.
    
    Sample Input : 
    9 10
    1 2
    2 3
    1 7
    2 4
    3 4
    4 7
    7 8
    9 7
    7 6
    5 6
    3
    4 2
    5 3
    2 10

    Answer: 
    4
    4
    3
*/
 
#include <bits/stdc++.h>
using namespace std;
 
 
void solve()
{
    int n, e;
    cin >> n >> e;
    // Construct Graph
    vector<int> adj[n];
    while(e--)
    {
        int s, end;
        cin >> s >> end;
        adj[s].push_back(end);
        adj[end].push_back(s);
    }
    int m;
    cin >> m;
    while(m--)
    {
        int source, depth;
        cin >> source >> depth;
        // bfs
        queue<int> q; bool visited[n]; int dist[n];
        for(int i = 0; i < n; i++) visited[i] = false;
        dist[source] = 0;
        q.push(source);
        visited[source] = true;
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(auto b : adj[a])
            {
                if(visited[b]) continue;
                visited[b] = true;
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
        int c = 0;
        for(int i = 0; i < n; i++)
            c += (dist[i] == depth);
        cout << c << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}