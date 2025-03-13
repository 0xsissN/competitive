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

const int INF = 1e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

vector<vi> adj;
vi ans;

bool dfs(int node, int prev){
    if(ans[node] != 0)
        return ans[node] != prev;

    ans[node] = prev == 1 ? 2 : 1;
    for(auto i : adj[node]){
        if(!dfs(i, ans[node]))
            return false;
    }

    return true;
}

void solve() {
    int V, m; cin >> V >> m;
    adj.resize(V + 1);
    ans.resize(V + 1);

    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool val = 0;
    FOR(i, 1, V + 1){
        val = dfs(i, 0);
        if(!val){
            cout << "IMPOSSIBLE" << N;
            return;
        }
    }

    FOR(i, 1, V + 1){
        cout << ans[i] << " ";
    }
    cout << N;
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