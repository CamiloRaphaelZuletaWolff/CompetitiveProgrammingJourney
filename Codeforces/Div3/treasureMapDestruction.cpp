#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {

        ll n; cin >> n;

        vector<ll> numeritos(n);

        for (ll i = 0; i < n; i++) {
            cin >> numeritos[i];
        }

        vector<ll> rangos(n + 1, 0);
        for (ll i = 0; i < n; i++) {

            ll d = numeritos[i];
            
            if (d <= 0) continue;
            
            ll l = max(0LL, i - d + 1);
            
            ll r = min(n - 1, i + d - 1);


            
            rangos[l]++;
            
            rangos[r + 1]--;
        }

        string lu(n, '0');


        ll aux = 0, total = 0;
        
        for (ll i = 0; i < n; i++) {
        
            aux += rangos[i];
        
            if (aux == 0) {
        
                lu[i] = '1';
                total++;
        
            }
        }

        bool roto = (total > 0);
        
        for (ll i = 0; i < n && roto; i++) {
        
            ll d = numeritos[i];
        
            if (d < 0) continue;

            bool hay = false;
        
            if (i - d >= 0 && lu[i - d] == '1') hay = true;
        
            if (i + d < n && lu[i + d] == '1') hay = true;


            
            if (!hay) roto = false;
        }

        if (roto) cout << lu << endl;
        else cout << -1 << endl;
    }
    return 0;
}