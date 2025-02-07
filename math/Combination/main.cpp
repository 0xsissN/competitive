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

const int INF = 998244353; 
const int MOD = 1e9 + 7;
const int tam = (int)1e5 + 10;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

//fact -> factorial
//facin -> factorial inverso
ll fact[tam], facin[tam];

ll comb(int n, int k){
	return fact[n] * facin[k] % MOD * facin[n - k] % MOD;
}

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

void solve() {
	fact[0] = facin[0] = 1;
	FOR(i, 1, tam){
		fact[i] = fact[i - 1] * i % MOD;
		facin[i] = pot(fact[i], MOD - 2);
	}
	
	cout << comb(100, 10) << N;
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T; cin >> T;
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */
