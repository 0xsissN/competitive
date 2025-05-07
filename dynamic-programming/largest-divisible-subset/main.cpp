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

void solve() {
    int n; cin >> n;
    vi nums(n);
    FOR(i, 0, n) cin >> nums[i];

    sort(all(nums));

    vi dp(n, 1), p(n, -1);
    int mx = 1, li = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }

        if(dp[i] > mx){
            mx = dp[i];
            li = i;
        }
    }

    vi res;
    for(int i = li; i >= 0; i = p[i]){
        res.pb(nums[i]);
        if(p[i] == -1) break;
    }

    for(auto i : res) cout << i << " ";
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