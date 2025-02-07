/*
    Autor: OracleShadow
    Problema: Optical Experiment [codeforce]
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define SORT(v) sort(all(v))

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> enter(n);
    vector<int> exit(n);

    FOR(i, 0, n){
        cin >> enter[i];
    }

    FOR(i, 0, n){
        cin >> exit[i];
    }

    vector<int> intersect(n, 0);

    FOR(i, 0, n){
        int a = ((exit[i] - enter[i]) + n);
        if(a<n){
            intersect[0]++;
        }else{
            intersect[((exit[i] - enter[i]) + n) % n]++;
        }
    }


    int maxInter = 0;
    FOR(i, 0, n){
        maxInter = max(maxInter, intersect[i]);
    }

    cout << maxInter << endl;
    return 0;
}

