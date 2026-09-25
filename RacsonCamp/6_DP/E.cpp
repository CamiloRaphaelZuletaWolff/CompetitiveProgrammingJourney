#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct ganadores {

    ll longitud;
    ll inicio;

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    ll l; cin>>l;

    vector<ll>partes (l+1,0);

    for (ll i = 1; i < l+1; i++)
    {
        cin>>partes[i];
    }

    vector<ll> dp (l+1, LLONG_MIN);
    dp[0] = 0;

    for (ll i = 1; i <= l; i++)
    {
        for (ll j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i-j] + partes[j]);
            
        }
        
        
    }

    cout<<dp[l];
    
    
    
    return 0;

}