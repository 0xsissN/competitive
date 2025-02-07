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

vi countSort(vi arr, int n){
    int k = *max_element(all(arr));

    int count[k+1] = {0};
    FOR(i, 0, n){
        count[arr[i]]++;
    }

    for(int i = 1; i <= k; i++){
        count[i] += count[i-1];
    }

    int output[n];
    for(int i = n-1; i >= 0; i--){
        output[--count[arr[i]]] = arr[i];
    }

    FOR(i, 0, n){
        arr[i] = output[i];
    }

    return arr;
}

void solve() {
    vi arr = {1,0,2,1,0};
    vi res = countSort(arr, sz(arr));
    FOR(i, 0, sz(res)){
        cout << res[i] << " ";
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
