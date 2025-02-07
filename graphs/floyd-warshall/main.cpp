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

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int INF = 2e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

ll n, m;

void floydWarshall(vector<vll>& graph){
	FOR(k, 0, n){
		FOR(i, 0, n){
			FOR(j, 0, n){
				if(graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[i][k] != INF && graph[k][j] != INF)){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	vector<vll> graph(n, vll(n, INF));
	FOR(i, 0, n)
		graph[i][i] = 0;
	
	FOR(i, 0, m){
		ll u, v, w; cin >> u >> v >> w;
		graph[u][v] = w;
	}
	
	floydWarshall(graph);
	
	FOR(i, 0, n){
		if(graph[i][i] < 0){
			cout << "NEGATIVE CYCLE" << N;
			return;
		}
	}
	
	FOR(i, 0, n){
		FOR(j, 0, n){
			if(graph[i][j] == INF){
				cout << "INF ";
			}else{
				cout << graph[i][j] << " ";
			}
		}
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
