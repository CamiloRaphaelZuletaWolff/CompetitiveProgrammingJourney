
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> dp (1000001,0);
vector<bool> vis(1000001,false);
vector<ll> coins;

ll solve (ll n){
    if(n == 0) return 1LL;
    // if(n == 1) return 1LL;
    
    if(vis[n]) return dp[n];

    for (ll i = 0; i < coins.size(); i++)
    {
        if(n - coins[i] >= 0){
            dp[n] = (dp[n] + solve(n - coins[i])) % (1000000000 + 7);
        }
    }
    vis[n] = true;


    return dp[n];



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ll n,x; cin>>n>>x;

    for (ll i = 0; i < n; i++)
    {
        ll z; cin>>z;
        coins.push_back(z);
    }
    ll res = solve(x);

    cout<<res;

    
    
    
    

    

    

}