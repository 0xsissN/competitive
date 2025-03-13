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
    La idea de esta solucion, es que como buscamos un orden, es util pensar en topological sort. la idea es insertar dentro de la cola
    todos los nodos que no tengan conexiones, ir sacandolos y guardarlos en el array 
*/

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    vi conn(n + 1);
    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        conn[v]++;
    }

    queue<int> q;
    FOR(i, 1, n + 1){
        if(conn[i] == 0){
            q.push(i);
        }
    }

    vi ans;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.pb(u);

        for(auto i : adj[u]){
            conn[i]--;
            if(conn[i] == 0){
                q.push(i);
            }
        }
    }

    if(sz(ans) == n){
        for(auto i : ans)
            cout << i << " ";
        cout << N;
    }else{
        cout << "IMPOSSIBLE" << N;
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