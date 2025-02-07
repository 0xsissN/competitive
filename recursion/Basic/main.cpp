#include <iostream>
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x) 
#define sz(x) int((x).size()) 
#define pb push_back
#define mk make_pair
#define N endl
#define ull unsigned long long int
#define ll long long int
#define DBG(x) cout << #x << " = " << (x) << endl;

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;

const int INF = 1e9 + 7; 
const int MOD = 998244353;
const int tam = (int)2e5 + 5;

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

//Print name n times
void printName(int n){
	if(n == 0)
		return;
	cout << "nashe" << N;
	printName(n - 1); 
}

//Print of 1 -> N
void printNumbers(int n, int cont){
	if(n + 1 == cont)
		return;
	cout << cont << N;
	printNumbers(n, cont + 1);
}

//Print of N -> 1
void printNumbersRev(int n){
	if(n == 0)
		return;
	cout << n << N;
	printNumbersRev(n - 1);
}

//Print sum 1..n
void sumNumbers(int n, int sum){
	if(n == 0){
		cout << sum << N;
		return;
	}
	sumNumbers(n - 1, sum + n);
}

//Reverse an array, same array
void reverseArray(int l, int r, vector<int> &a){
	if(l >= r)
		return;
	
	swap(a[l], a[r]);
	reverseArray(l + 1, r - 1, a);
}

void solve() {
	//printName(3);
	//printNumbersRev(10);
	//sumNumbers(10, 0);
	
	vector<int> a = {1,2,3,4,5};
	reverseArray(0, sz(a) - 1, a);
	for(auto i : a)
		cout << i << " ";
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
