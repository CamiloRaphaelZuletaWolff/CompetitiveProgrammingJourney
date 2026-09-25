#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MOD = 10007;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll a, b;
    ll k, n, m;
    
    cin >> a >> b >> k >> n >> m;

    vector<vector<ll>> pascal(k + 1, vector<ll>(k + 1, 0));
    for (ll i = 0; i <= k; ++i) {
        pascal[i][0] = 1;
        for (ll j = 1; j <= i; ++j) {
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
        }
    }
        


    ll coeficiente = pascal[k][n];
    ll potenciaA = power(a, n);
    ll potenciaB = power(b, m);

    ll res = (coeficiente * potenciaA) % MOD;
    res = (res * potenciaB) % MOD;

    cout << res;
    














    
    return 0;
}