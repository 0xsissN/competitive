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

ll low(ll a, ll b){
    ll res = 0;
    FOR(i, 0, b){
        res += a;
    }

    return res;
}

ll fast(ll a, ll b){
    if(b == 0) return 0;
    if(b % 2 == 0) return 2 * fast(a, b / 2);
    return 2 * fast(a, b / 2) + a;
}

void solve() {
    ll a, b; cin >> a >> b;
    cout << fast(a, b) << N;
    cout << low(a, b) << N;
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