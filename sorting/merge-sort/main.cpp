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

vi merge(vi &L, vi &R){
	vi res;
	int pL = 0, pR = 0;
	while(pL < sz(L) && pR < sz(R)){
		if(L[pL] < R[pR]){
			res.emplace_back(L[pL]);
			pL++;
		}else{
			res.emplace_back(R[pR]);
			pR++;
		}
	}
	while(pL < sz(L)){
		res.emplace_back(L[pL]);
		pL++;
	}
	
	while(pR < sz(R)){
		res.emplace_back(R[pR]);
		pR++;
	}
	
	return res;
}

vi mergeSort(vi &a){
	if(sz(a) <= 1)
		return a;
	int n = sz(a);
	vi L(a.begin(), a.begin() + n / 2), R(a.begin() + n / 2, a.end());
	L = mergeSort(L);
	R = mergeSort(R);
	
	return merge(L, R);
}

void solve() {
	vi a = {5,1,2,7,8,100,95};
	vi b = mergeSort(a);
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
