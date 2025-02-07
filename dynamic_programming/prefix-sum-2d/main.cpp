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
	int n, m; cin >> n >> m;
	vector<vi> a(n, vi(m));
	vector<vi> s(n, vi(m));
	
	FOR(i, 0, n){
		FOR(j, 0, m){
			cin >> a[i][j];
		}
	}
	
	FOR(i, 0, n){
		FOR(j, 0, m){
			s[i][j] = a[i][j];
			if(i)
				s[i][j] += s[i - 1][j];
			if(j)
				s[i][j] += s[i][j - 1];
			if(i && j)
				s[i][j] -= s[i - 1][j - 1];
		}
	}
	
	int res = INT_MIN;
	FOR(r1, 0, n){
		FOR(r2, r1, n){
			FOR(c1, 0, m){
				FOR(c2, c1, m){
					int cur = s[r2][c2];
					if(r1)
						cur -= s[r1 - 1][c2];
					if(c1)
						cur -= s[r2][c1 - 1];
					if(r1 && c1)
						cur += s[r1 - 1][c1 - 1];
					res = max(res, cur);
				}
			}
		}
	}
	
	cout << res << N;
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
