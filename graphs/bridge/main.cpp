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
#define DBG(x) cout << #x << " = " << (x) << endl;

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int INF = 1e9 + 7;
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b)
{
    return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll fdiv(ll a, ll b)
{
    return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down

int t = 1;

void dfsBridge(int node, int parent, vi &vis, vector<vi> adj, int tin[], int low[], vector<vi> &bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = t;
    t++;

    for (auto i : adj[node])
    {
        if (i == parent)
            continue;
        if (!vis[i])
        {
            DBG(i);
            dfsBridge(i, node, vis, adj, tin, low, bridges);
            cout << "-----" << N;
            DBG(node);
            DBG(i);

            low[node] = min(low[node], low[i]);

            if (low[i] > tin[node])
            {
                bridges.pb({i, node});
            }
        }
        else
        {
            low[node] = min(low[node], tin[i]);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    FOR(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    } 

    vi vis(n + 1, 0);
    int tin[n + 1], low[n + 1];
    vector<vi> bridges;

    dfsBridge(1, -1, vis, adj, tin, low, bridges);

    cout << sz(bridges) << N;
    for (auto i : bridges)
    {
        cout << i[0] << " " << i[1] << N;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    FOR(i, 0, T)
    {
        solve();
    }
    return 0;
}

/*
 *    Do you know who did it?
 *    GOD DID
 */