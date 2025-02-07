/* 
**    Autor: OracleShadow 
**    Problem: lonely integer [VJudge]
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

using namespace std; 
 
const int INF = 1e9; 
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int p; cin >> p;
    int res = 0; 
    while (p--)
    {
        int e; cin >> e;
        res ^= e;
    }
    cout << res;    
    return 0; 
}