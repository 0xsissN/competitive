/* 
**    Autor: OracleShadow 
**    Problem: How many paths are there to the solution? [UMSS]
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

// Function to count the roads to find '*'
int countRoad(vector<vector<char>> laberinto, int x, int y){
    int cont = 0;
    if(validate(laberinto, x, y)){
        if(laberinto[x][y] == '*'){
            cont = 1;
        }else{
            if(laberinto[x][y] != '#' && laberinto[x][y] != '@'){
                laberinto[x][y] = '@';
                cont = countRoad(laberinto, x + 1, y) + countRoad(laberinto, x, y + 1) + countRoad(laberinto, x - 1, y) + countRoad(laberinto, x, y - 1); 
                laberinto[x][y] = ' ';
            }
        }
    }
    return cont;
}

void grilla(){
    vector<vector<char>> laberinto = {
        {' ', ' ', '#', ' ', '#', '#', '#'},
        {' ', ' ', '#', ' ', ' ', '#', '#'},
        {' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', ' ', '#', ' ', '#', '#', ' '},
        {'*', ' ', '#', ' ', '#', '#', ' '}
    };
    int c = countRoad(laberinto, 0, 0);
    if(c == 0) cout << "No se puede encontrar '*'" << N;
    else cout << "Hay " << c << " roads to find '*'" << N;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    grilla();
    return 0; 
}
