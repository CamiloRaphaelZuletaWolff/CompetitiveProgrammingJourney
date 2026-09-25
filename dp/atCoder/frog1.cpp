#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k; cin>>n>>k;

    vector<ll> h(n+1);

    for (ll i = 1; i <= n; i++)
    {
        cin>>h[i];
    }

    vector<ll> dp(n+1,100000000000000);

    dp[0] = 0;
    dp[1]= 0;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if(i-j>=1){
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
        
        
    }

    cout<<dp[n];
    



    

    return 0;

}