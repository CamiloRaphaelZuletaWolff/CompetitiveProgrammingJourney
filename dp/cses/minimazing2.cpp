
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> dp (1000001,1000000000);

vector<bool> vis(1000001,false);
vector<ll> coins;
ll n = 0LL;
ll x = 0LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    cin>>n>>x;
    for (ll i = 0; i < n; i++)
    {
        ll z;cin>>z;
        coins.push_back(z);
    }

    dp[0] = 0;

    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 0; j < coins.size(); j++)
        {
            if(i-coins[j] >= 0){
                dp[i] = min(dp[i], (dp[i-coins[j]] +1));
            }
        }
    }


    if(dp[x] == 1000000000) cout<<-1;
    else cout<<dp[x];

    
    
    
    
    

    

    

}