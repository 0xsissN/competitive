/*
**    Autor: OracleShadow
**    Problem: 
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define SORT(v) sort(all(v))
#define N endl
#define pb push_back
#define ull unsigned long long
#define ll long long

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9;
const int tam = 200010;

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int t; cin >> t;
    while (t--){
        ull x; cin >> x;
        ull a = cbrt(x);
        ull aux = x - pow(a, 3);
        ull b = cbrt(aux);
        printf("%d %d %d\n", a, aux, b); 
        if(pow(a, 3) + pow(b, 3) == x) cout << "Yes" << N;
        else cout << "No" << N;
    }
    return 0; 
}