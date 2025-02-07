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
#define DBG(x) cout<<#x<<" = "<<(x)<<endl;

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

struct Node {
    int data;
    Node *left, *middle, *right;

    Node(int d){
        data = d;
        left = middle = right = nullptr;
    }
};

Node* buildTree(vi& data){
    if(data.empty())
        return nullptr;
    
    queue<Node*> q;
    Node* root = new Node(data[0]);
    q.push(root);
    int i = 1;

    while(!q.empty() && i < sz(data)){
        Node* act = q.front();
        q.pop();

        if(i < sz(data)){
            act->left = new Node(data[i]);
            q.push(act->left);
            i++;
        }

        if(i < sz(data)){
            act->middle = new Node(data[i]);
            q.push(act->middle);
            i++;
        }
        
        if(i < sz(data)){
            act->right = new Node(data[i]);
            q.push(act->right);
            i++;
        }
    }

    return root;
}

void printTree(Node* root){
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->middle);
    printTree(root->right);
}

void solve() {
    vi data = {1,2,3,4,5,6,7,8};
    Node* root = buildTree(data);

    printTree(root);
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