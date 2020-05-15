/*
* author - Sayan Bose
* link - https://codeforces.com/problemset/problem/368/B
* source - CodeForces
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    // pre_process
    int dp[n+1];
    memset(dp, 0, n+1);
    dp[n] = 1;
    map<int, int> freq;
    freq[v[n]] = 1;
    for(int i = n-1; i >= 0; i--)
    {
        if(!freq[v[i]])
        {
            freq[v[i]] = 1;
            dp[i] = dp[i+1] + 1;
        }
        else{
            dp[i] = dp[i+1];
        }
    }
    while(m--)
    {
        int l;
        cin >> l;
        cout << dp[l] << '\n';
    }
    return 0;
}