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

string add(string x, string y){
    reverse(all(x));
    reverse(all(y));

    string s, e;
    ll len = 0;

    if(sz(x) > sz(y)){
        len = sz(y);
        s = y;
        e = x; 
    }else{
        len = sz(x);
        s = x;
        e = y;
    }

    string ans;
    int div = 0;

    FOR(i, 0, len){
        int p = (x[i] - '0') + (y[i] - '0') + div;
        if(p > 9){
            ans += to_string(p%10);
            div = p/10;   
        }else{
            ans += to_string(p);
            div = 0;
        }
    }

    FOR(i, sz(s), sz(e)){
        int p = (e[i] - '0') + div;
        if(p > 9){
            ans += to_string(p % 10);
            div = p / 10;
        }else{
            ans += to_string(p);
            div = 0;
        }
    }

    reverse(all(ans));
    return ans;
}

void solve() {
    string a, b; cin >> a >> b;
    cout << add(a, b);
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