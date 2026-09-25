
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<ll>> dp(1000001, vector<ll>(100, 0));
vector<vector<bool>> vis(1000001, vector<bool>(100, false));

vector<ll> coins;

ll l;

ll solve (ll n, ll last){
    if(n == 0) return 1LL;
    // if(n == 1) return 1LL;
    
    if(vis[n][last]) return dp[n][last];

    for (ll i = l-1; i >= 0 ; i--)
    {
        if(n - coins[i] >= 0){
            if(i <= last){
                dp[n][last] = (dp[n][last] + solve(n - coins[i], i)) % (1000000000 + 7);
            }
        }
    }

    vis[n][last] = true;


    return dp[n][last];



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ll x; cin>>l>>x;

    for (ll i = 0; i < l; i++)
    {
        ll z; cin>>z;
        coins.push_back(z);
    }
    sort(coins.begin(),coins.end());
    ll res = solve(x, l);

    cout<<res;

    
    
    
    

    

    

}