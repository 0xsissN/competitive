#include <iostream>
#include <bits/stdc++.h>
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i <= (b); i++)
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
const int MOD = 998244353; // INF;
const int tam = (int)2e5 + 5;
 
ll cdiv(ll a, ll b)
{
    return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll fdiv(ll a, ll b)
{
    return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down
 
vector<vi> graph;
vector<bool> vst;
 
void DFS(int n)
{
    vst[n] = true;
    FOR(i, 0, sz(graph[n]))
    {
        if (!vst[graph[n][i]])
            DFS(graph[n][i]);
    }
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    graph.resize(n + 1);
    vst = vector<bool>(n + 1, false);
 
    FOR(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
 
    int comp = 0;
    vi ans;
 
    FORN(i, 1, n)
    {
        if (vst[i] == 0)
        {
            DFS(i);
            ans.pb(i);
            comp++;
        }
    }
 
    cout << comp - 1 << N;
    FOR(i, 1, sz(ans))
    {
        cout << ans[i - 1] << " " << ans[i] << N;
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