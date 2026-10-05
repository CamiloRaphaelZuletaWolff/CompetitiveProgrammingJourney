#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




vector<string> grid;

ll res = 0;

vector<vector<ll>> tablero(8,vector<ll>(8,0));

vector<ll> idx = {1,-1,0,0,1,1,-1,-1};

vector<ll> idy = {0,0,1,-1,1,-1,1,-1};


bool valido(ll fila, ll columna){

    for (ll i = 0; i < 8; i++)
    {
        for (ll j = 1; j <= 8; j++)
        {
            ll x = fila + j*idx[i];
            ll y = columna + j*idy[i];
            if(x>= 8 || x < 0 || y >=8 || y< 0) continue;

            if(tablero[x][y]== 1) return false;


        }
        

        
    }
    return true;
    


}




void solve(ll n){

    if(n == 8) {
        res++;
        return;
    }

    for (ll i = 0; i < 8; i++)
    {
        if(grid[n][i] == '*' || tablero[n][i] == 1 || !valido(n,i)){
            continue;
        }
        tablero[n][i] = 1;
        solve(n+1);
        tablero[n][i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    for (ll i = 0; i < 8; i++)
    {
        string s; cin>>s;
        grid.push_back(s);
    }

    solve(0);

    cout<<res<<endl;


    
    
    

    

    return 0;
    

}