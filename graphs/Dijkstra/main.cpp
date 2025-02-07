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

vector<vector<pair<int, int>>> graph;

vi dijkstra(int r, int n){
	vi dist(n, INF);
	dist[r] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, r});
	
	while(!pq.empty()){
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		if(d > dist[u])
			continue;
			
		for(auto i : graph[u]){
			int v = i.first;
			int w = i.second;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	
	return dist;
}

void solve() {
	int n, m, r; cin >> n >> m >> r;
	graph.resize(n);
	
	FOR(i, 0, m){
		int u, v, w; cin >> u >> v >> w;
		graph[u].pb({v, w});
		//graph[v].pb({u, w});
	}
	
	vi dist = dijkstra(r, n);
	for(auto i : dist){
		if(i == INF)
			cout << "INF" << N;
		else
			cout << i << N;
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
