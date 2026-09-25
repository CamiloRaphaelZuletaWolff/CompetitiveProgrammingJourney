#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll MOD = 100003;


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

int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    ll m, n;
    cin>>m>>n;

    ll a = power(m, n, MOD);
    ll b = m % MOD * power(m - 1, n - 1, MOD) % MOD;
    cout << ((a - b) % MOD + MOD) % MOD << "\n";

    return 0;
}