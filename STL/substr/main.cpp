#include <bits/stdc++.h>

using namespace std;

int main() {
    string cad, bus; cin >> cad >> bus;

    long long s = bus.size();
    int c = 0;
    long long r = s - 1;

    for (long long i = 0; i < cad.size()-r; i++) {
        if (cad.substr(i, s) == bus) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
