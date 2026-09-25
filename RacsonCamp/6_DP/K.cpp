#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MOD = 1000000007LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<vector<ll>> dp (n+1,vector<ll>(n+1,0));

    for (ll i = 0; i < n+1; i++)
    {
        dp[i][0] = 1;
    }
    

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if(j-i >= 0)
            dp[i][j] = (dp[i-1][j] + dp[i][j-i]) % MOD;   
        else{
            dp[i][j] = dp[i-1][j];
        }
    }
        
    }
    

    cout<<dp[n][n];

    


    

    return 0;

}