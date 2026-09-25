#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,m; cin>>n>>m;

    vector<ll> monedas(m);

    for (ll i = 0; i < m; i++)
    {
        cin>>monedas[i];
    }

    vector<ll> dp(n+1,10000000000);

    dp[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if(i - monedas[j] >=0)
            dp[i] = min(dp[i], dp[i-monedas[j]] + 1);
        }
        
    }

    cout<<dp[n];
    


    

    return 0;

}