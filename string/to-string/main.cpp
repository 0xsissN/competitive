/*
    Autor: OracleShadow
    Problem:
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

    int hh, mh, hs, ms;
    char p;
    cin >> hh >> p >> mh;
    cin >> hs >> p >> ms;
    int chh = (hh * 60) + mh;
    int chs = (hs * 60) + ms;
    int r = chs - chh;

    if(r == 0){
        cout << "00" << p << "00" << endl;
        return 0;
    }

    if(r < 60){
        cout << "00" << p << r << endl;
        return 0;
    }

    int rd = r / 60;
    int rrd;

    if(r != 60){
        rrd = r - (60 * rd);
    }

    string h, m;

    if(rd < 10){
        h = "0" + to_string(rd);
    }else {
        h = to_string(rd);
    }

    if(rrd < 10){
        m = "0" + to_string(rrd);
    } else {
        m = to_string(rrd);
    }

    cout << h << p << m << endl;
    return 0;
}
