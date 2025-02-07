/*
    Autor: OracleShadow
    Problem:
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define SORT(v) sort(all(v))

using namespace std;

const int INF = 1e9;

int countBinary(int l, int mc, int mu){
    if(l == 0){
        return 1;
    }
    if(mc < 0 || mu < 0){
        return 0;
    }
    int c = 0;
    if(mc > 0){
        c += countBinary(l - 1, mc - 1, mu);
    }
    if(mu > 0){
        c += countBinary(l - 1, mc, mu - 1);
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, mc, mu; cin >> l >> mc >> mu;
    int res = countBinary(l, mc, mu);
    cout << res << endl;
    return 0;
}
