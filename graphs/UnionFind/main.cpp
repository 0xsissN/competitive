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

struct UnionFind{
	vi a;
	vi b;

	UnionFind(int n): a(n), b(n){
		FOR(i, 0, n)
			a[i] = i;
	}

	int find(int u){
		return a[u] = (u == a[u]? u : find(a[u]));
	}

	void set_union(int u, int v){
		int pu = find(u);
		int pv = find(v);
		if(pu != pv){
			if(b[pu] < b[pv])
				swap(pu, pv);
			if(b[pu] == b[pv])
				b[pu]++;
			a[pv] = pu;
		}
	}

	bool is_same_set(int u, int v){
		return find(u) == find(v);
	}
};

void solve() {
	int n; cin >> n;
	UnionFind uf(n);
	vector<pair<int, int>> x;
	FOR(i, 0, n - 1){
		int u, v; cin >> u >> v;
		u--; v--;
		if(uf.is_same_set(u, v)){
			x.pb({u, v});
		}
		uf.set_union(u, v);
	}

	cout << sz(x) << N;
	int idx = 0, j = 0;
	FOR(i, 0, n){
		if(!uf.is_same_set(i, j)){
			cout << x[idx].first + 1 << " " << x[idx].second + 1 << " " << i + 1 << " " << j + 1 << N;
			uf.set_union(i, j);
			idx++;
		}
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
