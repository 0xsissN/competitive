#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
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

const int INF = (int)1e9; 
const int MOD = 998244353;  // INF;
const int tam = (int)1e6;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void solve() {
    vi dp(tam, INF);
    vi coins = {1, 3, 6, 10, 15};

    dp[0] = 0;

    FOR(i, 0, tam){
        for(auto j : coins){
            if(i + j < tam){
                dp[i + j] = min(dp[i + j], dp[i] + 1); 
            }
        }
    }

    ll q; cin >> q;
    while (q--)
    {
        int x; cin >> x;
        int ans = 0;
        if(x >= tam){
            int cont = (x - tam) / coins.back() + 5;
            x -= cont * coins.back();
            ans += cont; 
        }        

        cout << ans + dp[x] << N;
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