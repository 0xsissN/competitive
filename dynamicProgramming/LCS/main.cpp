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
	string a = "$", b = "$"; 
	string na, nb; cin >> na >> nb;
	a += na;
	b += nb;
	
	int ta = sz(a), tb = sz(b);
	vector<vi> graph(ta, vi(tb, 0));
	
	FOR(i, 1, ta){
		FOR(j, 1, tb){
			if(a[i] == b[j]){
				graph[i][j] = graph[i - 1][j - 1] + 1;
			}else{
				graph[i][j] = max(graph[i - 1][j], graph[i][j - 1]);
			}
		}
	}
	
	cout << graph[ta - 1][tb - 1] << N;
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
