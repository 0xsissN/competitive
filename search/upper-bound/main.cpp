#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define sor(x) sort(all(x))
#define pb push_back
#define N endl
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

int upperBound(vi arr, int n){
	int l = 0, h = sz(arr) - 1;
	int ans = sz(arr);
	while(l <= h){
		int md = (l + h) / 2;
		if(arr[md] > n){
			ans = md;
			h = md - 1;
		}else{
			l = md + 1;
		}
	}
	
	return ans;
}

void solve() {
	int n, q; cin >> n >> q;
	vi nums(n);
	FOR(i, 0, n)
		cin >> nums[i];
	
	while(q--){
		int x; cin >> x;
		int res = upper_bound(all(nums), x) - nums.begin();
		cout << res << " ";
		cout << upperBound(nums, x) << N;
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
