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
    string x; cin >> x;
    map<char, int> mp;

    for(auto i : x){
        mp[i]++;
    }

    int imp = 0, pi = 0, pd = sz(x) - 1;
    vector<char> res(sz(x));
    for(auto [f, s] : mp){
        if(s & 1){
            imp++;
            if(imp == 2){
                cout << "NO SOLUTION" << N;
                return;
            }
            if(s == 1){
                res[(pi + pd) / 2] = f; 
            }else{
                FOR(i, 0, s / 2){
                    res[pi] = f;
                    res[pd] = f;
                    pi++;
                    pd--;
                }
                res[(pi + pd) / 2] = f; 
            }
        }else{
            FOR(i, 0, s / 2){
                res[pi] = f;
                res[pd] = f;
                pi++;
                pd--;
            }
        }
    }

    for(auto i : res){
        cout << i;
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