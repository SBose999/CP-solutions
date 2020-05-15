/*
author - Sayan Bose
link - https://www.spoj.com/problems/COINS/
source - SPOJ
*/
#include<bits/stdc++.h>
#define ll long long
#define amaterasu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    amaterasu
    ll n;
    while(cin >> n){
    ll dp[n];
    dp[0] = 0;
    dp[1] = 1;
    for(ll i = 2; i<=n;i++){
        dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4], i);
    }
    cout << dp[n] << '\n';}
    return 0;
}