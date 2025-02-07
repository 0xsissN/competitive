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

int maxSubArraySum(vi& a, int n){
	int max_f = INT_MIN, max_e = 0;
	FOR(i, 0, n){
		max_e += a[i];
		if(max_f < max_e){
			max_f = max_e;
		}
		if(max_e < 0){
			max_e = 0;
		}
	} 
	
	return max_f;
}

void printMaxSubArraySum(vi& a, int n){
	int max_f = INT_MIN, max_e = 0, start = 0, end = 0, s = 0;
	
	FOR(i, 0, n){
		max_e += a[i];
		if(max_f < max_e){
			max_f = max_e;
			start = s;
			end = i; 
		}
		if(max_e < 0){
			max_e = 0;
			s = i + 1;
		}
	}
	
	cout << "Maximum sum " << max_f << N;
	cout << "Start " << start << " End " << end << N;
}

void solve() {
	vi a = {4, -5, 4, -3, 4, 4, -4, 4, -5};
	int res = maxSubArraySum(a, sz(a));
	printMaxSubArraySum(a, sz(a));
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
