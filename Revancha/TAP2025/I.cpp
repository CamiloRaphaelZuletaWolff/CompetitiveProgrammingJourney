#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n, m; cin >> n >> m;
    vector<ll> personas(n), decision(n);
    ll lu = 0LL;

    for (ll j = 0; j < m; j++) {
        ll x, y; cin >> x >> y;
        for (ll &e: decision) cin >> e;
        ll unos = count(decision.begin(), decision.end(),  1);
        ll dos = count(decision.begin(), decision.end(),  2);
        
        ll ines1 = x / (unos + 1LL);
        ll ines2 = y;
        bool op1 = ines1 >= ines2;

        for (ll i = 0; i < n; i++) {
            if (decision[i] == 1LL) {
                personas[i] += ((op1)? ines1: (x / unos));
            } else {
                personas[i] += y;
            }
        }
        lu += (op1? ines1 : ines2);
    }

    for (ll i = 0; i < n; i++) {
        cout << personas[i] << " ";
    }
    cout << lu <<'\n';

    return 0;

}