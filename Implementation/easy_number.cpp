/*
* author - Sayan Bose
* link - http://codeforces.com/problemset/problem/236/B
* source - CodeForces
*/
/*
Sample Input : 
5 6 7
Sample Output :
1520
*/
#include<bits/stdc++.h>
#define amaterasu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define MOD 1073741824
using namespace std;

ll divisors[1000001] = {0};

void preprocess()
{
    for(ll i = 1; i <= 1000000; ++i)
    {
        for(ll j = i; j<= 1000000; j+=i) divisors[j]++;
    }
}

int main()
{
    amaterasu
    preprocess();
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = 0;
    for(ll i = 1; i<=a; ++i)
    {
        for(ll j = 1; j<=b; ++j)
        {
            for(ll k = 1; k<=c; ++k)
            {
                res += divisors[i*j*k];
                res %= MOD;
            }
        }
    }
    cout << res;
    return 0;
}