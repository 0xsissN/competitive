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

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void intToBin(int x){
	for(int i = x; i >= 0; i--){
		if(x & (1 << i))
			cout << "1";
		else
			cout << "0";
	}
	
	cout << N;
}

void solve() {
	int x = 2147483647;
	DBG(x);
	x++;
	DBG(x);
	
	int andOpe = 10 & 7;
	DBG(andOpe);
	
	int orOpe = 13 | 9;
	DBG(orOpe);
	
	int xorOpe = 11 ^ 5;
	DBG(xorOpe);
	
	intToBin(4);
	string a = "1000";
	cout << stoi(a) << N;
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
