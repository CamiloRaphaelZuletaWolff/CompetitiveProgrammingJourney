#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



vector<ll> dp(99991, 0);

ll p;


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

vector<ll> cambioBase(ll x) {
    vector<ll> digitos;
    if (x == 0) digitos.push_back(0);
    while (x > 0) {
        digitos.push_back(x % p);  
        x /= p;                    
    }
    return digitos;
}

int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        ll n, m;
        cin>>n>>m>>p;
        dp[0] = 1 % p;
        
        for (ll i = 1; i < p; i++){
            dp[i] = dp[i - 1] * i % p;
        }

    
    vector<ll> digitosN = cambioBase(n+m);
    vector<ll> digitosK = cambioBase(n);

    while (digitosK.size() < digitosN.size()) {
        digitosK.push_back(0);
    }

    ll res = 1;

    for (ll i = 0; i < digitosN.size(); i++) {
        res = res * combinatoria(digitosN[i], digitosK[i]) % p;
    }

    cout<<res<<endl;



    }
    return 0;
}