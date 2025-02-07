#include <iostream>
#include <vector>

using namespace std;

int contarSubsecuenciasNoDecrecientes(string cadena) {
    int n = cadena.length();
    vector<long long> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] * 2;
        for (int j = i - 2; j >= 0; --j) {
            if (cadena[j] <= cadena[i - 1]) {
                dp[i] -= dp[j];
                break;
            }
        }
    }

    return dp[n] - 1;
}

int main() {
    string cadena;
    cin >> cadena;

    int resultado = contarSubsecuenciasNoDecrecientes(cadena);
    cout << resultado << endl;

    return 0;
}
