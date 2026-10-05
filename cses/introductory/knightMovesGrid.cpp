#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lu = 0;
ll n;



ll dx[] = {2, 2, -2, -2, 1,-1, 1,-1};
ll dy[] = {1,-1,  1,  -1,2, 2,-2,-2};


void bfs(ll x, ll y, vector<vector<ll>> &lu){
    
    queue<tuple<ll,ll,ll>> pilita;
    
    
    vector<vector<bool>> vis(n,vector<bool>(n,0));

    pilita.push({x,y,0});

    while(!pilita.empty()){

        auto [x1,y1,nivel] = pilita.front();
        pilita.pop();


        
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;

        if(vis[x1][y1]) continue;

        lu[x1][y1] = nivel;


        vis[x1][y1] = true;

        for (ll i = 0; i < 8; i++)
        {
            pilita.push({x1 + dx[i], y1+dy[i],nivel +1});
        }
    }




}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    cin>>n;

    vector<vector<ll>> lu(n,vector<ll>(n,0));
    

    bfs(0,0,lu);    

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {

            cout<<lu[i][j]<<" ";

        }

        cout<<endl;

    }
    




    return 0;

}