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

void res(vi& a, int n, int T){
	vi memo(n), len(n);
	FOR(i, 0, n){
		len[i] = 1;
		memo[i] = a[i];
		if(i and memo[i - 1] >= 0){
			memo[i] += memo[i - 1];
			len[i] += len[i - 1];
		}
	}
	
	int max_e = INT_MIN, start = -1, end = -2;
	FOR(i, 0, n){
		if(memo[i] <= 0)
			continue;
		if(max_e > memo[i])
			continue;
		if(max_e < memo[i]){
			max_e = memo[i];
			start = i - len[i] + 1;
			end = i;
			continue;
		}
		if(end - start + 1 > len[i])
			continue;
		if(end - start + 1 < len[i]){
			start = i - len[i] + 1;
			end = i;
			continue;	
		}
	}
	
	start++;
	end += 2;
	if(max_e >= 0){
		cout << "The nicest part of route " << T + 1 << " is between stops " << start << " and " << end << N;
	}else{
		cout << "Route " << T + 1 << " has no nice parts" << N;
	}
}

void solve(int T) {
	int n; cin >> n;
	vi nums(n);
	
	FOR(i, 0, n - 1)
		cin >> nums[i];
	
	res(nums, n - 1, T);
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T; cin >> T;
    FOR(i, 0, T) {
        solve(i);
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */
