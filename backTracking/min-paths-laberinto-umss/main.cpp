/* 
**    Autor: OracleShadow 
**    Problem: How many min pass to find '*' [UMSS]
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

// Function to count the min pass to find '*'
int countMinPass(vector<vector<char>> laberinto, int x, int y){
    int cant = INF;
    if(validate(laberinto, x, y)){
        if(laberinto[x][y] == '*'){
            cant = 0;
        }else{
            if(laberinto[x][y] != '#' and laberinto[x][y] != '@'){
                laberinto[x][y] = '@';
                int right = 1 + countMinPass(laberinto, x, y + 1);
                int down = 1 + countMinPass(laberinto, x + 1, y);
                int left = 1 + countMinPass(laberinto, x, y - 1);
                int up = 1 + countMinPass(laberinto, x - 1, y);
                laberinto[x][y] = ' ';
                cant = min(right, min(down, min(left, up)));
            }
        }
    }
    return cant;
}

void grilla(){
    vector<vector<char>> laberinto = {
        {' ', ' ', '#', ' ', '#', '#', '#'},
        {' ', ' ', '#', ' ', ' ', '#', '#'},
        {' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', ' ', ' ', ' ', '#', '#', ' '},
        {' ', ' ', '#', ' ', '#', '#', '*'}
    };

    int mp = countMinPass(laberinto, 0, 0);
    cout << "Los pasos minimos son: " << mp << N;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    grilla();
    return 0; 
}
