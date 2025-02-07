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

vi countingSort(vi &a){
	int M = *max_element(all(a)) - *min_element(all(a)) + 1;
	int OFFSET = *min_element(all(a));
	vi cnt(M, 0), head(M, 0);
	
	for(auto x : a)
		cnt[x - OFFSET] += 1;
	
	FOR(i, 1, M){
		head[i] = head[i - 1] + cnt[i - 1];
	}
	
	vi res(sz(a));
	
	for(auto x : a)
		res[head[x - OFFSET]++] = x;
	
	/* Ver indices de ordenamiento
	FOR(i, 0, sz(a)){
		res[head[a[i] - OFFSET]++] = i;
	}
	*/
	
	return res;
}

void solve() {
	vi a = {5,1,2,7,8,100,95};
	vi b = countingSort(a);
	for(auto i : b)
		cout << i << " ";
	cout << N;
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
