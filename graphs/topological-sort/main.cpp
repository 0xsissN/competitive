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
stack<int> q;

void topologicalSort(int node){
    visited[node] = 1;

    for(auto i : adj[node]){
        if(!visited[i]){
            topologicalSort(i);
        }
    }

    q.push(node);
}

void solve() {
    int V, m; cin >> V >> m;
    adj.resize(V);
    visited.resize(V, false);

    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    FOR(i, 0, V){
        if(!visited[i]){
            topologicalSort(i);
        }
    }

    vi ans;

    while(!q.empty()){
        ans.pb(q.top());
        q.pop();
    }

    FOR(i, 0, sz(ans)){
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