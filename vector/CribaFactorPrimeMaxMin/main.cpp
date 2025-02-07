/*
**    Autor: OracleShadow
**    Do you know who did it? GOD DID
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define N endl
#define pb push_back
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9 + 7;
const int tam = 2e5 + 10;

vi primeMin(int n){
    vi minp(n + 1);
    iota(all(minp), 0);

    for(int i = 4; i <= n; i += 2){
        minp[i] = 2;
    }

    for(int i = 3; i * i <= n; i += 2){
        if(minp[i] == i){
            for(int j = i * i; j <= n; j += 2*i){
                minp[j] = min(minp[j], i);
            }
        }
    }

    return minp;
}

vi primeMax(int n){
    vi maxp(n + 1);
    iota(all(maxp), 0);

    for(int i = 2; i <= n; i++){
        if(maxp[i] == i){
            for(int j = 2 * i; j <= n; j += i){
                maxp[j] = i;
            }
        }
    }
    return maxp;
}

void solve(vi minp){
    int n; cin >> n;
    cout << minp[n] << N;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    vi minp = primeMin(tam);
    vi maxp = primeMax(tam);
    FOR(i, 0, T){
        solve(maxp);
    }
    return 0;
}