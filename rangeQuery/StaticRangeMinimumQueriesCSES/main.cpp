/*
**    Autor: OracleShadow
**    Problem: Static Range Minimum Queries [VJudge]
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
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

int ST[tam * 4], L[tam * 4], R[tam * 4];

int sig2pot(int n){
    int p = 1;
    while(p < n){
        p *= 2;
    }
    return p;
}

int query(int n, int a, int b){
    if(R[n] < a || b < L[n]) return INF;
    if(a <= L[n] && R[n] <= b) return ST[n];
    return min(query(n*2, a, b), query(n*2 + 1, a, b));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vi v(n);
    FOR(i, 0, n) cin >> v[i];

    n = sig2pot(n);
    v.resize(n, INF);

    FOR(i, 0, n){
        ST[n + i] = v[i];
        L[n + i] = R[n + i] = n + i;
    }

    FORN(i, n - 1, 1){
        ST[i] = min(ST[i * 2], ST[i * 2 + 1]);
        L[i] = L[i * 2];
        R[i] = R[i * 2 + 1];
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << query(1, a - 1 + n, b - 1 + n) << N;
    }

    return 0;
}
