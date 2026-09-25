#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;
    

    vector<ll> numeritos(n+1,0);

    for (ll i = 1; i <= n; i++)
    {
        cin>>numeritos[i];
    }

    if(n == 1){
        cout<<max(0LL,numeritos[1]);
        return 0;
    }

    vector<ll> dp(n+1,0);

    dp[n] = max(0LL, numeritos[n]);
    dp[n-1] = max({0LL, numeritos[n-1],numeritos[n]});

    


    for (ll i = n-2; i >= 0; i--)
    {
        dp[i] = max(dp[i+1],dp[i+2] + numeritos[i]);
    }

    cout<<max(dp[0],0LL);
    
    



    return 0;

}