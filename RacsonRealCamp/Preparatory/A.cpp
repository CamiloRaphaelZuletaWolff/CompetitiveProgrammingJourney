#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll ceros = 0;

bool isValid (ll numero, ll posX, ll posY, ll cerosLeft, vector<vector<ll>> gridActual){

    // bool valido = true;
    ll n = gridActual[0].size();
    for (ll i = 0; i < n; i++)
    {   
        if(posY + i >=n) continue;

        if(numero == gridActual[posX][posY+i]){
            return false;
        }
    }
    for (ll i = 0; i < n; i++)
    {   
        if(posY - i < 0) continue;

        if(numero == gridActual[posX][posY-i]){
            return false;
        }
    }
    for (ll i = 0; i < n; i++)
    {   
        if(posX + i >=n) continue;

        if(numero == gridActual[posX+ i][posY]){
            return false;
        }
    }
    for (ll i = 0; i < n; i++)
    {   
        if(posX - i < 0) continue;

        if(numero == gridActual[posX-i][posY]){
            return false;
        }
    }

    return true;


}

vector<vector<ll>> solve (ll numero, ll posX, ll posY, ll cerosLeft, vector<vector<ll>> gridActual){

        ll n = gridActual[0].size();

    if(cerosLeft == 0){
        return gridActual;
    }


    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(isValid(numero,posX,posY,cerosLeft,gridActual)){            
                for (ll k = numero; k <= 9; k++)
                {
                    solve(k,posX+1,posY,cerosLeft,gridActual);
                }
            }
        }
        
    }
    
    

    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n;
    cin>>n;

    vector<vector<ll>>original(n*n,vector<ll>(n*n,0));

    for (ll i = 0; i < n*n; i++)
    {
        for (ll j = 0; j < n*n; j++)
        {
            cin>>original[i][j];
            if(original[i][j] == 0)ceros++;
            
        }
        
    }

    vector<vector<ll>> res = solve(1,0,0,ceros,original);
    

    return 0;

}