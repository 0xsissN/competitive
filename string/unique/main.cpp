/* 
**    Autor: OracleShadow 
**    Problem: Buscador [OmegaUp]
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
 
using namespace std; 
 
const int INF = 1e9;    
int F[1000009];
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    string a; cin >> a;
    
    SORT(a);
    auto f = unique(all(a));
    a.erase(f, a.end());
    int n; cin >> n;
    
    int contm = 0;
    string se = "";

    while (n--){
        string nc; cin >> nc;
        string aux = nc;
        int cont = 0;

        SORT(nc);
        auto nf = unique(all(nc));
        nc.erase(nf, nc.end());
    
        FOR(i, 0, sz(nc)){
            FOR(j, 0, sz(a)){
                if(a[j] == nc[i]){
                    cont++;
                    break;            
                }
            }
            if(cont > contm){
                contm = cont;
                se = aux;
            }
        }    
    }
    
    cout << se << N;
    
    return 0; 
}