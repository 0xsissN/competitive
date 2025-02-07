/* 
**    Autor: OracleShadow 
**    Problem: Laberinto/Buscando '*' [UMSS]
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

// Function to validate position
bool validate(vector<vector<char>> laberinto, int x, int y){
    return x >= 0 && x < laberinto.size() && y >= 0 && y < laberinto[0].size();  
}

// Function to return true or false depending if find '*'
bool success(vector<vector<char>> laberinto, int x, int y){
    bool res = false;
    if(validate(laberinto, x, y)){
        if(laberinto[x][y] == '*'){
            res = true;
        } else {
            if(laberinto[x][y] != '#' && laberinto[x][y] != '@'){
                laberinto[x][y] = '@';
                res = success(laberinto, x + 1, y) || success(laberinto, x, y + 1) || success(laberinto, x - 1, y) || success(laberinto, x, y - 1); 
            }
        }
    }
    return res;
}

bool grilla(){
    vector<vector<char>> laberinto = {
        {' ', ' ', '#', ' ', '#', '#', '#'},
        {' ', ' ', '#', ' ', ' ', '#', '#'},
        {' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' '},
        {'#', ' ', '#', ' ', '#', '#', ' '},
        {' ', ' ', '#', ' ', '#', '#', '*'}
    };
    return success(laberinto, 0, 0); 
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    bool r = grilla();
    cout << r << N;
    return 0; 
}
