#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define pb push_back
#define mk make_pair
#define N "\n"
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int INF = 998244353; 
const int MOD = 1e9 + 7;
const int tam = (int)1e5 + 10;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

ll fact[tam], facin[tam];

ll pot(ll b, ll e){
	ll res = 1;
	while(e){
		if(e & 1){
			res = b * res % MOD;
		}
		b = b * b % MOD;
		e /= 2;
	}
	
	return res;
}

ll bino(int n, int k){
	return fact[n] * facin[n - k] % MOD * facin[k] % MOD;
}

void solve() {
	fact[0] = facin[0] = 1;
	FOR(i, 1, tam){
		fact[i] = fact[i - 1] * i % MOD;
		facin[i] = pot(fact[i], MOD - 2);
	}
	
	int a, b, c, d;
	while(cin >> a >> b >> c >> d){
		cout << bino(a, b) * pot(bino(c, d), b) % MOD << N;
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
