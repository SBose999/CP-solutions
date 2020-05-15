/*
* author - Sayan Bose
* link - https://codeforces.com/problemset/problem/347/B
* source - CodeForces
*/
/*
Sample Input:
5
0 1 3 4 2
Sample Output:
3
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    vector<int> vec(n);
    map<int, int> v;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp == i) c++;
        else{
            v[temp] = i;
        }
        vec[i] = temp;
    }
    int p = 0;
    for(int i = 0; i < n; i++){
        if(i != vec[i])
        {
            if(vec[v[i]] == i && vec[i] == v[i]) {p = max(p, 2); break;}
            else if(vec[v[i]] == i || vec[i] == v[i]) p = max(p, 1);
        }
    }
    cout << c + p << '\n';
    return 0; 
}