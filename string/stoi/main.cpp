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
    bool comp = 0;

    FOR(i, 0, sz(x)){
        if(x[i] == '0'){
            comp = 1;
            break;
        } 
    }

    if(comp){
        string a = "";
        int s = sz(x) / 2;
        FOR(i, 0, s){
            a += x[i];
        }

        string b = "";
        FOR(i, s, sz(x)){
            b += x[i];
        }

        if(b[0] == '0') cout << -1 << N;
        else{
            if(stoi(b) > stoi(a)){
                cout << a << " " << b << N;
            }else{
                cout << -1 << N;
            }
        }        
    }else{
        char a = x[0];
        string b = x.substr(1, sz(x));
        if(stoi(b) > a - '0'){
            cout << a << " " << b << N;
        }else{
            cout << -1 << N;
        }
    }
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
