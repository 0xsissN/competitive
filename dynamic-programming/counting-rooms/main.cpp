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

const int INF = 1e9 + 7; 
const int MOD = 998244353;  // INF;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

/*
void sg(vector<vll> a, int n){
    FOR(i, 0, n){
        FOR(j, 0, n){
            cout << a[i][j] << " ";
        }
        cout << N;
    }
}
*/

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    FOR(i, 0, n)
        cin >> grid[i];
    
    vector<vll> npaths(n, vll(n, 0));
    npaths[0][0] = (grid[0][0] == '.');

    FOR(i, 0, n){
        FOR(j, 0, n){
            if(grid[i][j] != '*'){
                if(i - 1 >= 0 && grid[i - 1][j] != '*')
                    npaths[i][j] = (npaths[i][j] + npaths[i - 1][j]) % INF;
                if(j - 1 >= 0 && grid[i][j - 1] != '*')
                    npaths[i][j] = (npaths[i][j] + npaths[i][j - 1]) % INF;
            }

            //sg(npaths, n);
            //cout << "---------------" << N;
        }
    }

    cout << npaths[n - 1][n - 1] << N;
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