
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
const int tam = 1e5 + 10;

vi getPrimes(int n){
    vector<bool> a(n + 1, 1);
    vi primes = {2};  
    a[0] = a[1] = 0;
    for(int i = 4; i <= n; i+= 2){
        a[i] = 0;
    }
    for(int i = 3; i <= n; i += 2){
        if(a[i]){
            primes.pb(i);
            if((ll)i * i <= n){
                for(int j = i * i; j <= n; j += 2*i){
                    a[j] = 0;
                }
            }
        }
    }
    return primes;
}

// MAX 1e14
bool isPrime(int n, vi primes){
    if(n == 1) return false;
    for(int p : primes){
        if((ll)p * p > n) break;
        if(n % p == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    vi primes = getPrimes(tam);
    int n; cin >> n;
    cout << isPrime(n, primes) << N;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    FOR(i, 0, T){
        solve();
    }
    return 0;
}