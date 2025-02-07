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
    ll n; cin >> n;
    ll sm = (n * (n + 1)) / 2;
    if(sm & 1){
        cout << "NO" << N;
        return;
    }

    vi a, b;
    if(n & 1){
        cout << "YES" << N;
        b.pb(n);
        n--;
        FOR(i, 1, (n / 2) + 1){
            if(i & 1){
                a.pb(i);
                a.pb(n - i + 1);
            }else{
                b.pb(i);
                b.pb(n - i + 1);
            }
        }
    }else{
        cout << "YES" << N;
        FOR(i, 1, (n / 2) + 1){
            if(i & 1){
                a.pb(i);
                a.pb(n - i + 1);
            }else{
                b.pb(i);
                b.pb(n - i + 1);
            }
        }
    }

    cout << sz(a) << N;
    for(auto i : a)
        cout << i << " ";
    cout << N;
        
    cout << sz(b) << N;
    for(auto i : b)
        cout << i << " ";
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