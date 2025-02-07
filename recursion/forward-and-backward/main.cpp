/* 
**    Autor: OracleShadow 
**    Problem: Forward and Backward [CodeForce]
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
 
const int INF = 1e9; 

bool isPalin(string a){
    return a == string(a.rbegin(), a.rend());
}

bool conver(int n, int b){
    string num = "";
    int r = 0;
    while (n > 0)
    {
        r = n % b;
        num += to_string(r);
        n /= b;
    }
    return isPalin(num);
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ull n; cin >> n;
    ull c = 0;
    FORN(i, 2, n){
        if(conver(n, i)){
            cout << i << " ";
            c += 1;
        }
    }
    if(c == 0) cout << "*";
    cout << N;
    return 0; 
}