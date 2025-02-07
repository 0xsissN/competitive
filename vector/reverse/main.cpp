/*
    Autor: OracleShadow
    Problema: FutureLab Triangulos [OmegaUp]
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
    vector<int> nums(n);

    FOR(i, 0, n){
        cin >> nums[i];
    }

    SORT(nums);
    reverse(all(nums));
    
    int a, b, c;
    a = nums[0];
    b = nums[1];
    c = nums[2];

    if(a + b > c && a + c > b && b + c > a){
        int res = a+b+c;
        cout << res << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}