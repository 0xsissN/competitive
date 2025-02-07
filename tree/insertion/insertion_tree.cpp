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
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int d){
    if(root == nullptr){
        root = new Node(d);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* act = q.front();
        q.pop();

        if(act->left != nullptr)
            q.push(act->left);
        else{
            act->left = new Node(d);
            return root;
        }

        if(act->right != nullptr)
            q.push(act->right);
        else{
            act->right = new Node(d);
            return root;
        }
    }
}

void preOrder(Node* root){
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void solve() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    preOrder(root);
    
    insertNode(root, 5);
    cout << N;
    
    preOrder(root);
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