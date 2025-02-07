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
    Node* left, * right, * middle;
    Node(int d){
        data = d;
        left = right = middle = nullptr;
    }
};

void push(Node** tail_ref, Node* node){
    if(*tail_ref == nullptr){
        *tail_ref = node;
        node->left = node->middle = node->right = NULL;
        return;
    }

    (*tail_ref)->right = node;
    node->left = (*tail_ref);
    node->right = node->middle = NULL;
    (*tail_ref) = node;
}

void TernaryTree(Node* root, Node** head_ref){
    if(root == NULL)
        return;
    
    static Node* tail = NULL;

    Node* left = root->left;
    Node* middle = root->middle;
    Node* right = root->right;

    if(*head_ref == NULL)
        *head_ref = root;
    
    push(&tail, root);

    TernaryTree(left, head_ref);
    TernaryTree(middle, head_ref);
    TernaryTree(right, head_ref);
}

void printList(Node* head){
    printf("Created double linked list is:\n");
    while(head){
        printf("%d ", head->data);
        head = head->right;
    }
}

void solve() {
    Node* root = new Node(30);
    root->left = new Node(5);
    root->middle = new Node(11);
    root->right = new Node(63);
 
    root->left->left = new Node(1);
    root->left->middle = new Node(4);
    root->left->right = new Node(8);
 
    root->middle->left = new Node(6);
    root->middle->middle = new Node(7);
    root->middle->right = new Node(15);
 
    root->right->left = new Node(31);
    root->right->middle = new Node(55);
    root->right->right = new Node(65);

    Node* head = NULL;
    TernaryTree(root, &head);
    printList(head);
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