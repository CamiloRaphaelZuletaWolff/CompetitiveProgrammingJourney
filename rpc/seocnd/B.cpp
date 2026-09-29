#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll res = 0;

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

void floodFill(ll x, ll y, vector<vector<ll>> &grid, vector<vector<bool>> &vis) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (vis[x][y] || grid[x][y] == 0) return;
    if(grid[x][y] == '#') return;

    vis[x][y] = true;
    res++;

    for (ll k = 0; k < 4; k++) {
        floodFill(x + dx[k], y + dy[k],grid,vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    while(cin>>n>>m && n != 0 && m != 0){
    
    vector<vector<ll>> grid(n,vector<ll>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    res = 0;

    ll l = 0, r = 0;

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            char c; cin>>c;
            if(c == '*'){
                l = i, r=j;
            }
            grid[i][j] = c;
    
        }
    }

    floodFill(l, r,grid,vis);

    cout<<res<<endl;

}

    return 0;
}