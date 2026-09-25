
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> dp (1000001,0);

ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ll n; cin>>n;
    vector<ll> dp(1000001,0);

    dp[0] = 1;


    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j < 7; j++)
        {
            if(i-j >= 0){
                dp[i] = (dp[i] + dp[i-j]) %  MOD;
            }
        }
        
    }

    cout<<dp[n];
    
    
    
    
    

    

    

}