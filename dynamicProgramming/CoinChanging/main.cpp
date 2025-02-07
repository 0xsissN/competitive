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

const int INF = 1e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void solve() {
	int t, n; cin >> t >> n;
	vi coin(n);
	FOR(i, 0, n)
		cin >> coin[i];
		
	vector<vi> graph(n, vi(t + 1));
	
	FOR(i, 0, t + 1){
		graph[0][i] = i;
	}
	
	FOR(i, 1, n){
		FOR(j, 1, t + 1){
			if(j >= coin[i]){
				graph[i][j] = min(graph[i - 1][j], 1 + graph[i][j - coin[i]]);
			}else{
				graph[i][j] = graph[i - 1][j];
			}
		}
	}
	
	cout << graph[n - 1][t] << N;
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
