#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define sor(x) sort(all(x))
#define pb push_back
#define N endl
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9 + 7; 
const int MOD = 998244353;  // INF;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

// SUM IN RANGE 

struct segtree {
    int n;
    vector<vi> a;
    vector<vll> s;
    segtree(int mx) {
        n = 1;
        while (n < mx) n <<= 1;
        a.resize(n * 2);
        s.resize(n * 2, vll(1));
    }   

    void set(int i, int x){
        a[n + i] = {x};
        s[n + i].pb(x);
    }

    void init(){
        for(int i = n-1; i >= 1; i--){
            int l = i<<1, r = l|1;
            merge(a[l].begin(),a[l].end(),
                  a[r].begin(), a[r].end(),
                  back_inserter(a[i]));

            s[i] = vll(a[i].size() + 1);
            for(int j = 0; j < sz(a[i]); ++j) s[i][j+1] = s[i][j] + a[i][j];
        }
    }

    ll get(int i, int x){
        int j = upper_bound(a[i].begin(), a[i].end(), x) - a[i].begin();
        return s[i][j];
    }

    ll solve(ll l, ll r, ll x){
        l += n; r += n;
        ll res = 0;
        while (l < r)
        {
            if(l&1) res += get(l, x), l++;
            if(r&1) r--, res += get(r, x);
            l >>= 1, r >>= 1;
        }

        return res;
    }
};

void solve() {
    int n; cin >> n;
    segtree t(n);
    FOR(i, 0, n){
        int a; cin >> a;
        t.set(i, a);
    }

    t.init();
    int a; cin >> a;
    ll ans = 0;

    while (a--)
    {
        ll w, x, y; cin >> w >> x >> y;
        w ^= ans;
        x ^= ans;
        y ^= ans;
        w--;
        ans = t.solve(w, x, y);
        cout << ans << N;
    }
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T = 1;
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */