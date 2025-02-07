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
const int tam = 1e6 + 10;

void solve(){
    string x; cin >> x;
    vll lMay, lMin;

    FOR(i, 0, x.size()){
        char o = x[i];
        if(o == 'B'){
            if(sz(lMay)){
                lMay.pop_back();
            }
        }else if(o == 'b') {
            if(sz(lMin)){
                lMin.pop_back();
            }
        }else if(o >= 'a' && o <= 'z'){
            lMin.pb(i);
        }else{
            lMay.pb(i);
        }
    }

    set<ll> st;
    for(auto i : lMay) st.insert(i);
    for(auto i : lMin) st.insert(i);
    string res;
    for(auto i : st) res += x[i];
    
    cout << res << N;
}

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T; cin >> T;
    FOR(i, 0, T){
        solve();
    }
    return 0; 
}