#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define pb push_back
#define mk make_pair
#define N endl
#define ull unsigned long long int
#define ll long long int
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int INF = 1e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool validate(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, vector<vector<char>>& gr){
    gr[x][y] = '#';

    FOR(i, 0, 4){
        int a = x + dx[i], b = y + dy[i];
        if(validate(a, b) && gr[a][b] == '.'){
            dfs(a, b, gr);
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> gr(n, vector<char>(m));
    FOR(i, 0, n){
        FOR(j, 0, m){
            cin >> gr[i][j];
        }
    }

    int cont = 0;
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(gr[i][j] == '.'){
                dfs(i, j, gr);
                cont++;
            }
        }
    }

    cout << cont << N;
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T = 1;
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */