/*
**    Autor: OracleShadow
**    Do you know who did it? GOD DID 
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
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9;
const int tam = 200010;

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int a, d, b, c; cin >> a >> d >> b >> c;
    int res = 0;
    int x = min(a, min(b, c));
    res = x * 256;
    cout << res + (min(d, a - x)) << N;
    return 0; 
}