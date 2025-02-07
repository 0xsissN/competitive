/*
**    Autor: OracleShadow
**    Problem: Recursión con memorización [OmegaUp]
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
#define ull unsigned long long

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9;
const int tam = 200010;
int cont = 0;

int fsum(int a, int b, int c){
    cont += 1;
    if(min(a, min(b, c)) <= 3){
        
        return a + (2 * b) + (3 * c);
    }else if(min(a, min(b, c)) > 3 && a + b + c == 100){
        
        return 0;
    }else{
        
        return fsum(a - 1, b - 1, c - 1) + fsum(a, b - 3, c - 3) + fsum((a / 2), b, c);
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int a, b, c; cin >> a >> b >> c;
    int res = fsum(a, b, c);
    printf("%d %d\n", res, cont);
    return 0; 
}