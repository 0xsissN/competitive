/* 
**    Autor: OracleShadow 
**    Problem: usado mochila_EvaluaciónRecursividad [OmegaUp]
*/ 
 
#include <iostream> 
#include <bits/stdc++.h> 
 
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define FORN(i, a, b) for (int i = (a); i <= (b); i++) 
#define all(v) v.begin(), v.end() 
#define sz(v) ((int)(v).size()) 
#define SORT(v) sort(all(v)) 
#define N endl 
#define pb push_back 
#define ll long long 

using namespace std; 
 
const int INF = 1e9; 
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int cosas, mochila; cin >> cosas >> mochila;
    vector<int> beneficios(cosas);
    vector<vector<int>> dp(cosas + 1, vector<int>(mochila + 1, 0));
    
    FOR(i, 0, cosas){
        cin >> beneficios[i] >> volumenes[i];    
    }
    
    FORN(f, 1, cosas){
        FORN(c, 1, mochila){
            //cout << f << " " << c << N;
            if(volumenes[f - 1] <= c){
                //cout << dp[f - 1][c] << " " << volumenes[f - 1] << " " << beneficios[f - 1] << " " << dp[f - 1][c - volumenes[f - 1]] << N;
                dp[f][c] = max(dp[f - 1][c], (dp[f - 1][c - volumenes[f - 1]]) + (beneficios[f - 1]));
            }else {
                //cout << dp[f - 1][c] << N;
                dp[f][c] = dp[f - 1][c];
            }
        }
    }
    
    //FORN(i, 0, cosas){
    //    FORN(j, 0, mochila){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << N;
    //}

    cout << dp[cosas][mochila] << endl;
    
    return 0;
}
