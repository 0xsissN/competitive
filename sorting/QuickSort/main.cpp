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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

void partition(vi &a, vi &L, vi &R, int pivot){
	FOR(i, 0, sz(a)){
		if(i == pivot)
			continue;
		if(a[i] < a[pivot])
			L.emplace_back(a[i]);
		else
			R.emplace_back(a[i]);
	}
}

vi quickSort(vi &a){
	if(sz(a) <= 1)
		return a;
	int n = sz(a);
	int pivot = random(0, n - 1);
	vi L, R;
	partition(a, L, R, pivot);
	L = quickSort(L);
	R = quickSort(R);
	L.emplace_back(a[pivot]);
	L.insert(L.end(), R.begin(), R.end());
	return L;
}

void solve() {
	int n; cin >> n;
	vi nums(n);
	FOR(i, 0, n)
		cin >> nums[i];
	vi b = quickSort(nums);
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
