#include <bits/stdc++.h>

using namespace std;

int main() {
    string cad = "bbbabbacb";
    string bus = "bb";

    int res = 0;

    for (int i = 0; i < cad.size(); i++) {
        int pos = cad.find(bus, i);
        if (pos != string::npos && pos > i) {
            res++;
            i = pos + bus.size();
        }
    }

    cout << "El número de ocurrencias de 'bb' en la cadena es: " << res << endl;

    return 0;
}
