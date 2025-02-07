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

bool isCyclic_util(vector<vi> adj, vector<bool> visit, int act){
    if(visit[act] == true)
        return true;
    
    visit[act] = true;
    bool f = false;

    for(auto i : adj[act]){
        f = isCyclic_util(adj, visit, i);
        if(f == true)
            return true;
    }

    return false;
}

bool isCyclic(int V, vector<vi> adj){
    vector<bool> visit(V, false);
    bool f = false;

    FOR(i, 0, V){
        visit[i] = true;
        for(auto j : adj[i]){
            f = isCyclic_util(adj, visit, j);
            if(f == true)
                return true;
        }
        visit[i] = false;
    }  

    return false;
}

// GRAFOS DIRIGIDOS 
void solve() {
    int V, m; cin >> V >> m; 
    vector<vi> adj(V);

    FOR(i, 0, m){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    cout << ((isCyclic(V, adj)) ? "Yes" : "No") << N;    
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