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

vector<string> vs;

void preCalc(){
    vs.pb("0");
    vs.pb("1");
    int ss = 0;
    FOR(i, 0, 17){
        int tt = sz(vs);
        int aux = ss;
        FOR(j, 0, tt - ss){
            vs.pb("0" + vs[aux]);
            aux++;
        }

        aux = tt - 1;
        FOR(k, 0, tt - ss){
            vs.pb("1" + vs[aux]);
            aux--;
        }

        ss = pow(2, i + 1) + ss;
    }
}

void solve() {
    int n; cin >> n;
    int stt = 0;
    FOR(i, 1, n){
        stt += pow(2, i);
    }

    FOR(i, stt, stt + pow(2, n)){
        cout << vs[i] << N;
    }
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T = 1;
    preCalc();
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */