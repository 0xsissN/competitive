#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define pb push_back
#define mk make_pair
#define N endl
#define ull unsigned long long int
#define ll long long int
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const long long INF = 1e18; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    FOR(i, 0, m){
        ll u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = min(w, dist[u][v]);
    }

    FOR(i, 1, n + 1){
        dist[i][i] = 0;
    }

    FOR(k, 1, n + 1){
        FOR(i, 1, n + 1){
            FOR(j, 1, n + 1){
                if(i != k && j != k && i != j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    FOR(i, 0, q){
        int u, v; cin >> u >> v;
        if(dist[u][v] == INF){
            cout << -1 << N;
        }else{
            cout << dist[u][v] << N;
        }
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