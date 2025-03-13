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

ll cdiv(ll a, ll b)
{
    return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll fdiv(ll a, ll b)
{
    return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down

vector<vector<pair<int, int>>> mp;
vector<vector<bool>> visited;
int sx, sy, ex, ey, n, m;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool validate(int x, int y)
{
    return ((x >= 0 && x < n && y >= 0 && y < m) && (!visited[x][y]));
}

void bfs()
{
    queue<pi> q;
    q.push({sx, sy});

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (auto mv : moves)
        {
            int mvx = mv.first;
            int mvy = mv.second;
            if (validate(mvx + cx, mvy + cy))
            {
                q.push({mvx + cx, mvy + cy});
                visited[mvx + cx][mvy + cy] = 1;
                mp[mvx + cx][mvy + cy] = {mvx, mvy};
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    mp.resize(n);
    visited.resize(n);
    FOR(i, 0, n)
    {
        mp[i].resize(m);
        visited[i].resize(m);
    }

    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            mp[i][j] = {-1, -1};
            char x;
            cin >> x;
            if (x == '#')
            {
                visited[i][j] = 1;
            }
            if (x == 'A')
            {
                sx = i;
                sy = j;
            }
            if (x == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }

    bfs();

    if (!visited[ex][ey])
    {
        cout << "NO" << N;
        return;
    }

    cout << "YES" << N;
    vector<pi> ans;
    pi end = {ex, ey};

    while (end.first != sx || end.second != sy)
    {
        ans.pb(mp[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }

    reverse(ans.begin(), ans.end());
    cout << sz(ans) << N;
    for (auto i : ans)
    {
        if (i.first == 1 && i.second == 0)
            cout << 'D';
        if (i.first == -1 && i.second == 0)
            cout << 'U';
        if (i.first == 0 && i.second == 1)
            cout << 'R';
        if (i.first == 0 && i.second == -1)
            cout << 'L';
    }
    cout << N;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    FOR(i, 0, T)
    {
        solve();
    }
    return 0;
}

/*
 *    Do you know who did it?
 *    GOD DID
 */