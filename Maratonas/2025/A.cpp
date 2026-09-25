#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n, m; cin>>n>>m;

    vector<vector<ll>> grid(n,vector<ll>(m,0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
        
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }



    ll res = 0;

    for (ll i = 0; i < m; i++)
    {
        ll maxi = LLONG_MIN;
        for (ll j = 0; j < n; j++)
        {
            maxi = max(maxi,grid[j][i]);
        }
        res += maxi;
        
    }

    cout<<res;

    
    

    return 0;

}