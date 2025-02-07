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
/*
int binarySearch(vi arr, int b){
	int s = 0, e = sz(arr) - 1;
	while(s <= e){
		int md = s + (e - s) / 2;
		if(arr[md] == b){
			return md;
		}else if(arr[md] < b){
			s = md + 1;
		}else{
			e = md - 1;
		}
	}

	return -1;
}
*/

void solve() {
	int n, q; cin >> n >> q;
	vi nums(n);
	FOR(i, 0, n)
		cin >> nums[i];
	
	while(q--){
		int x; cin >> x;
		int s = 0, e = n - 1;
		while(s < e){
			int md = s + (e - s) / 2;
			if(nums[md] < x)
				s = md + 1;
			else
				e = md;
		}
		cout << (nums[s] == x ? "YES" : "NO") << N;
		/*
		cout << (binary_search(all(nums), x) ? "YES" : "NO") << N;
		int res = binarySearch(nums, x);
		if(res == -1)
			cout << "NO" << N;
		else
			cout << "YES" << N;
		*/
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
