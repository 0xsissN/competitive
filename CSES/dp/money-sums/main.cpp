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
    int sm = 0;
    FOR(i, 0, n){
        int x; cin >> x;
        nums[i] = x;
        sm += x;
    } 

    vi dp(sm + 1, 0);
    dp[0] = 1;
    int r = 0;

    FOR(i, 0, n){
        for(int j = sm; j >= 0; j--){
            if(j - nums[i] < 0) break;
            if(dp[j - nums[i]] == 1){
                dp[j] = 1;
            }
        }
    }

    FOR(i, 1, sm + 1){
        if(dp[i] == 1){
            r++;
        }
    }

    cout << r << N;
    
    FOR(i, 1, sm + 1){
        if(dp[i] == 1){
            cout << i << " ";
        }
    }

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