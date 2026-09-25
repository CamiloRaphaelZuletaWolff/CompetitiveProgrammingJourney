#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n; cin>>n;

    vector<ll> numeritos(n,0);
    for (ll i = 0; i < n; i++)
    {
        cin>>numeritos[i];
    }

    vector<ll> dp(n+1,1);

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j >= 0; j--)
        {
            if(numeritos[i]> numeritos[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        
    }

    ll maxi = -1000;

    for (ll i = 0; i < n+1; i++)
    {
        maxi = max(maxi,dp[i]);
    }

    cout<<maxi;
    
    
    

    return 0;

}