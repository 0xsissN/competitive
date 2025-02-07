#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
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
const int MOD = 998244353;  // INF;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void solve() {
    ll n, x; cin >> n >> x;
    vll nums(n);
    FOR(i, 0, n) cin >> nums[i];

    vll dp(n + 1);
    dp[0] = 0;

    FOR(i, 1, n + 1){
        dp[i] = dp[i - 1] + nums[i - 1];
    }

    while (x--)
    {
        ll a, b; cin >> a >> b;
        cout << dp[b] - dp[a - 1] << N;
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