#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



vector<ll> dp(2*1000005, 0);

ll p = 1000000007;


ll power(ll base, ll exp,ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll combinatoria(ll n, ll k){
    if (k > n) return 0;

    ll numerador = dp[n];
    ll denominador = dp[k] * dp[n - k] % p;

    return numerador * power(denominador, p - 2, p) % p;

}


int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n,m; 
    cin>>n>>m;

    vector<ll>equis(m);
    
    dp[0] = 1;
    for (ll i = 1; i < dp.size(); i++){
        dp[i] = dp[i - 1] * i % p;
    }


    ll contador =0;
    for (ll i = 0; i < m; i++)
    {
        cin>>equis[i];
        contador += equis[i]+1;
    }

    n = n -contador;

    ll res = combinatoria(n+m-1,m-1);

    cout<<res;

    


    

    return 0;
}