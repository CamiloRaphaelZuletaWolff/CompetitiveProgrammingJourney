#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n,m;

bool roto = false;

char valido(ll i1, ll j1, vector<string> &grid, vector<vector<bool>> &vis){

    char actual = grid[i1][j1];

    map<char,bool>mapita;

    mapita['A'] = false;

    mapita['B'] = false;
    
    mapita['C'] = false;
    
    mapita['D'] = false;

    mapita[actual] = true;

    ll dx = i1-1;
    ll dy = j1 -1;

    if(dx >= 0) mapita[grid[dx][j1]] = true;
    if(dy >= 0) mapita[grid[i1][dy]] = true;

    for(auto [a,b] : mapita){
        if(!b) return a;
    }
    return 'x';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    

    cin>>n>>m;

    vector<string>grid;

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for (ll i = 0; i < n; i++)
    {
        string s;cin>>s;
        grid.push_back(s);
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            grid[i][j] = valido(i,j,grid,vis);
        }
        
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            // if(j!=0) cout<<" ";
            cout<<grid[i][j];
        }
        cout<<endl;
        
    }
    
    

    




    return 0;

}