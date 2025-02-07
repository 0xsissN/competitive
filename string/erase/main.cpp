/*
    Autor: OracleShadow
    Problema:
*/

#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i+=2)
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

    string a;
    string ter = "wxyz";
    while(cin >> a){
        string probe = "";
        probe = a;
        probe.erase(unique(all(probe)), probe.end());
        if(sz(probe) > 2){
            int com = 0, x = 0;
            FOR(i, 0, sz(probe)){
                if(probe[i] != ter[x] && x <= 3){
                    com++;
                }
                x++;
            }
            if(com > 0){
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        }else if(probe[0] == 'w' || probe[0] == 'x' || probe[0] == 'y' || probe[0] == 'z'){
            cout << 1 << endl;
        }
    }
    return 0;
}

