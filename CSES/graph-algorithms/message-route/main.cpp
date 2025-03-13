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
vector<bool> visited;

void bfs(int node, vi& r){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    r[node] = -1;

    while(!q.empty()){
        int act = q.front();
        q.pop();

        for(auto i : adj[act]){
            if(r[i] == 0){
                r[i] = act;
                q.push(i);
            }
        }
    }
}

void solve() {
    int V, m; cin >> V >> m;
    adj.resize(V + 1);
    visited.resize(V + 1);

    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi r(V + 1);

    bfs(1, r);
    if(r[V] == 0){
        cout << "IMPOSSIBLE" << N;
    }else{
        int n = V;
        vi path;
        while(n != -1){
            path.pb(n);
            n = r[n];
        }    
        reverse(all(path));
        cout << sz(path) << N;
        for(auto i : path)
            cout << i << " ";
        cout << N;
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