#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define pb push_back
#define mk make_pair
#define N endl
#define ull unsigned long long int
#define ll long long int
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
 
const long long INF = 1e18; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;
 
ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down
 
void solve() {
    ll n, m; cin >> n >> m;
    ll r = floor(log2(n));
    vector<vll> dp(r + 1, vll(n, INF));
    FOR(i, 0, n){
        cin >> dp[0][i];
    }
 
    FOR(i, 1, r + 1){
        FOR(j, 0, n){
            if(j + pow(2, i - 1) < n){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + pow(2, i - 1)]);
            }
        }
    }
 
    while(m--){
        int l, r; cin >> l >> r;
        l--;
        r--;
        int len = r - l + 1;
        int p = floor(log2(len));
        int k = pow(2, p);
 
        cout << min(dp[p][l], dp[p][r - k + 1]) << N;
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