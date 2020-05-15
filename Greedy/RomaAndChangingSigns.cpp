// author - Sayan Bose
// URL : https://codeforces.com/contest/262/problem/B
// source : CodeForces

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i= 0; i<n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++)
	{
		if(arr[i] < 0)
		{
			if(k){
				arr[i] *= -1;
				k--;
			}
			else{
				break;
			}
		}
	}
	if(k)
	{
		int m = 1e9;
		for(int i = 0; i < n; i++) m = min(m, arr[i]);
		for(int i = 0; i < n; i++)
		{
			if(arr[i] == m)
				if(k % 2 != 0)
				{
					arr[i]*=-1;
					k = 0;break;
				}
		}
	}
	int s = 0;
	for(int i = 0; i < n; i++)
		s += arr[i];
	cout << s << '\n';
	return 0;
}