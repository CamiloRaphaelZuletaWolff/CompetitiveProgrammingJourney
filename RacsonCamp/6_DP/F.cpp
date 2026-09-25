#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct objeto{
    ll valor;
    ll peso;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    ll n, w; cin>>n>>w;

    vector<objeto> cosas;

    for (ll i = 0; i < n; i++)
    {
        ll x,y; cin>>x>>y;

        cosas.push_back({x,y});

    }

    vector<ll> dp(w+1,0);


    for (ll i = 0; i < n; i++)
    {
        for (ll j = w; j >= 1; j--)
        {
            if(j- cosas[i].peso >= 0)
            dp[j] = max(dp[j], dp[j-cosas[i].peso] + cosas[i].valor);
            
        }
        
    }
    

    cout<<dp[w];
    


    

    return 0;

}