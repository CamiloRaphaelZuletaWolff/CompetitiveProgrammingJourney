#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,g;cin>>n>>g;
    vector<ll> arr(n+2);
    vector<ll> pref(n+2);
    vector<ll> dp(n+2,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i+1];
        pref[i+1] = arr[i+1]+pref[i];
    }
    ll mx = 0;
    ll acc = 0;
    while(true){
        acc+=mx;

        if(acc+mx+1>n){
            break;
        }
        mx++;
    }

    ll last = acc;
    for (int i = mx; i >= 1; i--)
    {
        last-=i;
        for (int i = n; i >= 0; i--)
        {
            dp[i] = max(dp[i],dp[i+1]);    
        }        
        for (int j = last; j <= n-i; j++)
        {
            dp[j+1] = max(g-(pref[j+i]-pref[j])+dp[j+i+1],dp[j+1]);
        }
    }
    ll res  =0;
    for (int i = 0; i <= n; i++)
    {
        res = max(dp[i],res);
    }
    cout<<res<<"\n";    
    

    return 0;

}