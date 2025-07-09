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

const int INF = 5e5 + 5; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

ll ft[INF], ar[INF];
int n, q;

int LSB(int x){
    return x&(-x);
}

void update(int pos, int val){
    while(pos <= n){
        ft[pos] += val;
        pos += LSB(pos);
    }
}

ll sum(int pos){
    ll res = 0;
    while(pos > 0){
        res += ft[pos];
        pos -= LSB(pos);
    }
    return res;
}

ll sum_range(int l, int r){
    return sum(r) - sum(l - 1);
}

void solve() {
    cin >> n >> q;
    FOR(i, 1, n + 1){
        ll x; cin >> x;
        ar[i] = x;
        update(i, x);
    }

    while(q--){
        int k, a, b; cin >> k >> a >> b;
        if(k == 1){
            update(a, b - ar[a]);
            ar[a] = b;
        }else{
            cout << sum_range(a, b) << N;
        }   
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