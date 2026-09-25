#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p = 0;

ll power(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
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

ll legendre(ll t, ll q) {
    ll e = 0;
    while (t > 0) {
        t /= q;
        e += t;
    }
    return e;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    ll t, n, m;
    cin >> t >> n >> m >> p;

    ll numerador = n - m + 1;
    ll denominador = n - 2 * m + 1;

    vector<bool> esCompuesto(numerador + 1, false);

    ll res = 1 % p;
    for (ll q = 2; q <= numerador; q++) {
        if (esCompuesto[q]) continue;
        for (ll j = q * q; j <= numerador; j += q) {
            esCompuesto[j] = true;
        }

        ll e = legendre(numerador, q) - legendre(denominador, q);
        if (e > 0) {
            res = res * power(q, e, p) % p;
        }
    }

    cout << res << "\n";

    return 0;
}