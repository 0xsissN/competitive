#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define sor(x) sort(all(x))
#define pb push_back
#define N endl
#define ull unsigned long long int
#define ll long long int

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1e9 + 7; 
const int MOD = 998244353;  // INF;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
 return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
 return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

void countSort(vi &arr, int n, int exp){
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
		int aux = (arr[i] / exp) % 10;
        output[count[aux] - 1] = arr[i];
        count[aux]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vi &arr, int n){
    int m = *max_element(all(arr));
    for(int exp = 1; m / exp > 0; exp *= 10){
		countSort(arr, n, exp);
	}
}

void solve() {
    vi nums = {70, 45, 75, 90, 802, 24, 2, 66};
    radixSort(nums, sz(nums));

    FOR(i, 0, sz(nums)){
        cout << nums[i] << " ";
    }
    cout << N;
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int T = 1;
    FOR(i, 0, T) {
        solve();
    }
    return 0; 
}

/*
 *    Do you know who did it? 
 *    GOD DID 
 */
