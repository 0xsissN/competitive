/*
**    Autor: OracleShadow
**    Do you know who did it? GOD DID
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define N endl
#define pb push_back
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9 + 7;
const int tam = 2e5 + 10;

void solve(){
    int n, q; cin >> n >> q;
    vi nums(n, 0);
    FOR(i, 0, n) cin >> nums[i];
    sort(nums.rbegin(), nums.rend());

    while (q--){
        int o, e; cin >> o >> e;
        e--;
        if(o == 1){
            nums[e] = 1 - nums[e];
            sort(nums.rbegin(), nums.rend());    
        }else{
            cout << nums[e] << N;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    FOR(i, 0, T){
        solve();
    }
    return 0;
}