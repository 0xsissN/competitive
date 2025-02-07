/*
**    Autor: OracleShadow
**    Do you know who did it? GOD DID 
**    Problem: Dynamic Range Sum Queries CSES
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define FORN(i, a, b) for (long long i = (a); i <= (b); i++)
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

const int INF = 5e5 + 5;
const int tam = 200010;

ll ft[INF];
ll ar[INF];
int n;
int q;

int LSO(int x){
    return x&(-x);
}

void update(int pos, int val){
    while(pos <= n){
        ft[pos] += val;
        pos += LSO(pos);
    }
}

long long sum(int pos){
    long long res = 0;
    while(pos > 0){
        res += ft[pos];
        pos -= LSO(pos);
    }
    return res;
}

long long sum_range(int l, int r){
    return sum(r) - sum(l-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    FORN(i, 1, n){
        ll x; cin >> x;
        ar[i] = x;
        update(i, x);
    }

    while(q--){
        int k, a, b; cin >> k >> a >> b;
        if(k == 1){
            update(a, b - ar[a]);
            ar[a] = b;
        }else{
            cout << sum_range(a, b) << N;
        }
    }
    return 0;
}
