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
    int n; cin >> n;
    vll nums(n);
    FOR(i, 0, n)
        cin >> nums[i];
    
    sort(all(nums));
    ll sum = 0;
    for(auto i : nums){
        if(i - sum > 1){
            break;
        }else{
            sum += i;
        }
    }

    cout << sum + 1 << N;
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
