/* 
**    Autor: OracleShadow 
**    Problem: Mochila / Maximizar teniendo un limite [UMSS]
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
 
int maxGanancia(vector<vector<int>> bag, int i, int j, int k){
    int maxg = 0;
    if(k > 0){
        if(i < bag.size()){
            if(j < bag[i].size()){
                maxg = bag[i][j] + max(maxGanancia(bag, i, j + 1, k - 1), maxGanancia(bag, i + 1, 0, k - 1));
                maxg = max(maxg, maxGanancia(bag, i + 1, 0, k));
            }else{
                maxg = maxGanancia(bag, i + 1, 0, k);
            }
        }
    }
    return maxg;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    vector<vector<int>> bag = {
      {3, 6, 8, 2, 2, 5, 6, 1, 2, 3, 1, 4},
      {4, 1, 1, 1, 1, 70, 4, 1, 5, 3, 2, 3},
      {10, 3, 2, 6, 6, 2, 3, 1, 6, 2, 3, 2},
      {1, 4, 3, 8, 4, 9, 2, 1, 6, 5, 4, 1}  
    };

    int res = maxGanancia(bag, 0, 0, 7);
    cout << res << N;
    return 0; 
}
