#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int a, b;
    while(n--){
        cin >> a >> b;
        string all = "";
        for(int i = a; i <= b; i++){
            all += to_string(i);
        }
        int cu = count(all.begin(), all.end(), '1');
        cout << cu << endl;
        cu = 0;
    }
    return 0;
}
