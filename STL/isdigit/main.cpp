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

void solve() {
    string x; cin >> x;
    vi nums;
    vector<char> letter;
    FOR(i, 0, sz(x)){
        if(isdigit(x[i])) nums.pb(x[i] - '0');
        else letter.pb(x[i]);
    }

    FOR(i, 0, sz(nums)){
        int s = nums[i];
        char c = letter[i];
        FOR(i, 0, s){
            cout << c;
        }
    }

    cout << N;
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T; cin >> T;
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */