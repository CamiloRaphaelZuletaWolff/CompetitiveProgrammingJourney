
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> dp (1000001,0);

ll solve (ll n){
    if(n == 0) return 1LL;
    if(n == 1) return 1LL;
    
    if(dp[n] != 0) return dp[n];

    for (ll i = 1; i <= 6; i++)
    {
        if(n - i >= 0)
        dp[n] = (dp[n] + solve(n-i)) % (1000000000 + 7);
    }


    return dp[n];



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ll n; cin>>n;



    ll res = solve(n);

    cout<<res;

    
    
    
    

    

    

}