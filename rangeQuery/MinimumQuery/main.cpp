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
const int tam = 2e5 + 5;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

const int LOG = 17;
int a[tam * 4];
int m[tam * 4][LOG];

int query(int l, int r){
	int len = r - l + 1;
	int k = 31 - __builtin_clz(len);
	return min(m[l][k], m[r - (1 << k) + 1][k]);
}

void solve() {
	int n, q; cin >> n >> q;
	
	FOR(i, 0, n){
		cin >> a[i];
		m[i][0] = a[i];
	}
	
	FOR(k, 1, LOG){
		for(int i = 0; i + (1 << k) - 1 < n; i++){
			m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}
	
	while(q--){
		int l, r; cin >> l >> r;
		l--; r--;
		cout << query(l, r) << N;
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
