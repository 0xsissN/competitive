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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    while(n--){
        float a,b,c; cin>>a>>b>>c;
        if(a == b){
            cout<<0<<endl;
            continue;
        }
        if(b > a) swap(a, b);
        int cnt = 0;
        while(a > b){
            a -= c;
            b += c;
            cnt++;
        }
        cout<<cnt<<endl;
        cnt = 0;
    }
    return 0;
}
