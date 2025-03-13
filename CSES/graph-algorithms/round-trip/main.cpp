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

/*
    La idea de esta resolucion, es recorrer todos los nodos para ver si existe un ciclo, si en caso se cumpla, imprimimos todos los padres
    que se almacenaron. Para detectar un ciclo se utiliza el algoritmo de DFS, si un nodo ya fue visitado y no es el padre, entonces
    se encontro un ciclo.
*/

int n, m, sv, ev; 
vector<vi> adj;
vi vis;
vi parent;

bool dfs(int node, int p){
    vis[node] = 1;
    parent[node] = p;

    for(auto j : adj[node]){
        if(j == p) continue;
        if(vis[j]){
            sv = j;
            ev = node;
            return true;
        }else{
            if(dfs(j, node)) 
                return true;
        }
    }

    return false;
}

bool visitAll(){
    FOR(i, 1, n + 1){
        if(!vis[i]){
            if(dfs(i, -1)) return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    parent.resize(n + 1);

    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(!visitAll()){
        cout << "IMPOSSIBLE" << N;
        return;
    }

    int tv = ev;
    vi ans;
    ans.pb(ev);

    while(tv != sv){
        ans.pb(parent[tv]);
        tv = parent[tv];
    }
    ans.pb(ev);

    cout << sz(ans) << N;
    for(auto i : ans){
        cout << i << " ";
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