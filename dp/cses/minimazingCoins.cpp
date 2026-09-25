
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> dp (1000001,-1);

vector<bool> vis(1000001,false);
vector<ll> coins;
ll n = 0LL;
ll x = 0LL;


ll solve (ll n){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    
    ll res = 100000000;
    for (ll i : coins)
    {
        if(n-i >= 0){
            ll aux = solve(n-i);
  
            if(aux >= 100000000) continue;

            res= min(res,aux+1) ;
        }
    }

    dp[n] = res ;

    return dp[n];
    



}

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
    


    ll res = solve(x);

    if(res >= 100000000){
        cout<<-1;
        return 0;
    }


    cout<<res;

    
    
    
    

    

    

}