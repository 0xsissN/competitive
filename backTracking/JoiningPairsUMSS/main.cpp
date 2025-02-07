/* 
**    Autor: OracleShadow 
**    Problem: Joining Pairs [VJudge] 
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
 
void impGra(vector<vector<int>> matrix){ 
    FOR(i, 0, sz(matrix)){ 
        FOR(j, 0, sz(matrix[0])){ 
            cout << matrix[i][j] << " "; 
        } 
        cout << N; 
    } 
} 

bool validate(vector<vector<int>> matrix, int x, int y){ 
    return x >= 0 && x < sz(matrix) && y >= 0 && y < sz(matrix[0]) && matrix[x][y] == 0; 
} 
  
bool uMatrix(int x, int y, int a, int b, vector<vector<int>>& matrix){ 
    bool res = false; 
    if(validate(matrix, x, y)){ 
        matrix[x][y] = 1;
        if(x == a && y == b){ 
            res = true; 
        }else{ 
            res = uMatrix(x, y + 1, a, b, matrix) || uMatrix(x + 1, y, a, b, matrix) || uMatrix(x, y - 1, a, b, matrix) || uMatrix(x - 1, y, a, b, matrix); 
        } 
    } 
    return res; 
} 
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n, m; cin >> n >> m; 
    int t; cin >> t; 
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    while (t--)
    {
        int x, y, a, b; cin >> x >> y >> a >> b;
        bool r = uMatrix(x, y, a, b, matrix);
        cout << r << N;
        impGra(matrix);
    }
    return 0; 
}