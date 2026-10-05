#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;


void mex(ll x, ll y, vector<vector<ll>> &grid){

    map<ll,ll> mapita;
    for (ll i = 0; i <= 3*n; i++)
    {
        mapita[i] = 0;
    }

    for (ll i = 1; i < n; i++)
    {
        
        if(y-i >= 0) mapita[grid[x][y-i]]++;
        if(x-i >= 0)mapita[grid[x-i][y]]++;
        
    }
    // cout<<"Nunca me fui"<<endl;
    // cout<<x<<" "<< y<<endl;
    // for(auto [a,b] : mapita){
    //     cout<<a<<" "<<b<<endl;
    // }
    // cout<<"Yo estoy re tranqui"<<endl;

    for(auto [a,b] : mapita){
        if(b == 0) {
            // cout<<"siempre xd "<<a<<endl;
            grid[x][y] = a;
            return;
        }
    }
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    cin>>n;

    vector<vector<ll>> grid(n,vector<ll>(n,0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            mex(i,j,grid);
            
        }
        
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(j !=0) cout<<" ";
            // cout<<i<<" "<<j<<" "<<grid[i][j];
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    
    




    




    return 0;

}