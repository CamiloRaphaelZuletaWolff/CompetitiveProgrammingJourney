#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,q; cin>>n>>q;
    

    vector<ll> numeritos(n,0);

    for (ll i = 0; i < n; i++)
    {
        cin>>numeritos[i];
    }

    vector<ll> dp (n+1,0);
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + numeritos[i-1];
    }

    for (ll i = 0; i < q; i++)
    {
        
        ll l, r; cin>>l>>r;

        cout<<dp[r] - dp[l]<<endl;


    }
    
    
    return 0;

}