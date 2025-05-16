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
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

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

int n, m; 
vi nums;
vector<vi> dp(100100, vi(110, -1));

int add(int x, int y){
    return (x + y) % INF;
}

int C(int i, int x){
    if(dp[i][x] != -1) return dp[i][x];
    if(x == 0 || x == m + 1) return dp[i][x] = 0;
    if(nums[i] != 0 && nums[i] != x) return dp[i][x] = 0;
    if(i == n - 1) return dp[i][x] = 1;

    return dp[i][x] = add(add(C(i + 1, x + 1), C(i + 1, x)), C(i + 1, x - 1));
}

void solve() {
    cin >> n >> m;
    nums.resize(n);
    FOR(i, 0, n) cin >> nums[i];

    int ans = 0;
    for(int x = 1; x < m + 1; x++){
        ans = add(ans, C(0, x));
    }

    cout << ans << N;
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