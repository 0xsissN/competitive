#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i <= (b); i++)
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

const int A = 30 + 3, K = 50 + 5;
int dp[A][A][K];

void fill_dp(){
    FOR(i, 0, A){
        FOR(j, 0, A){
            FOR(l, 0, K){
                if(l > i * j){
                    dp[i][j][l] = INF;
                    continue;
                }
                
                if(l == 0 || l == i * j){
                    dp[i][j][l] = 0;
                    continue;
                }

                dp[i][j][l] = INF;

                FOR(i1, 1, i){
                    FORN(l1, 0, l){
                        int i2 = i - i1, l2 = l - l1;
                        dp[i][j][l] = min(dp[i][j][l], dp[i1][j][l1] + dp[i2][j][l2] + j * j);
                    }
                }

                FOR(j1, 1, j){
                    FOR(l1, 0, l){
                        int j2 = j - j1, l2 = l - l1;
                        dp[i][j][l] = min(dp[i][j][l], dp[i][j1][l1] + dp[i][j2][l2] + i * i);           
                    }
                }
            }
        }
    }
}

void solve() {
    fill_dp();

    int p; cin >> p;
    while (p--)
    {
        int n, m, k; cin >> n >> m >> k;
        cout << dp[n][m][k] << N;
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