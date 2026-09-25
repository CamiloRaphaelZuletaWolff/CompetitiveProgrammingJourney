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

    ll maximoValor = 0;


    for (ll i = 0; i < n; i++)
    {
        ll x,y; cin>>x>>y;

        maximoValor+= x;

        cosas.push_back({x,y});

    }

    vector<ll> dp(maximoValor+1,1000000000000);

    dp[0] = 0;


    for (ll i = 0; i < n; i++)
    {
        for (ll j = maximoValor; j >= 1; j--)
        {
            if(j-cosas[i].valor >= 0)
            dp[j] = min(dp[j], dp[j-cosas[i].valor] + cosas[i].peso);
        }
    }

    ll res = 0;


    for (ll i = 0; i < dp.size(); i++)
    {

        if(dp[i] <= w){

            res = i;
        }

    }
    
    

    cout<<res;
    


    

    return 0;

}