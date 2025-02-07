/* 
**    Autor: OracleShadow 
**    Problem: Combinatoria [UMSS]
*/ 
 
#include <iostream> 
#include <bits/stdc++.h> 
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define FORN(i, a, b) for (int i = (a); i > (b); i--) 
#define all(v) v.begin(), v.end() 
#define sz(v) ((int)(v).size()) 
#define SORT(v) sort(all(v)) 
#define N endl 
#define pb push_back 
#define ll long long 

using namespace std; 
 
const int INF = 1e9; 
 
void imp(vector<char> comb){
    FOR(i, 0, sz(comb)){
        cout << comb[i] << " ";
    }
    cout << N;
}

void combinar(vector<char> conj, int i, int k, vector<char> comb){
    if(sz(comb) == 2){
        imp(comb);
    }else if(i < sz(conj)){
        comb.pb(conj[i]);
        combinar(conj, i + 1, k, comb);

        comb.pop_back();
        combinar(conj, i + 1, k, comb);
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<char> conj = {'A', 'B'};
    int k = 2;
    vector<char> comb;
    combinar(conj, 0, k, comb);
    return 0; 
}