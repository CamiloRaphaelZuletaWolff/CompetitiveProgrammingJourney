#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll MOD = 1e9 +7;


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

    ll n; cin>>n;
    
    cout<<power(2,n,MOD);

    return 0;
}