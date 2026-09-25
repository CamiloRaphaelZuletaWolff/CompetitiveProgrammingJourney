#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {

        ll n; cin >> n;

        vector<ll> lu(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> lu[i];
        }

        ll primero = -1;      
        ll ultimoUno = -1;    
        ll izq = -1, der = -1, l = 0;

        for (ll j = 0; j < n; j++)
        {
            if (lu[j] == 0) continue;

            if (primero == -1) primero = j;

            ll i;

            if(ultimoUno != -1){
                i = ultimoUno;
            }else{
                i = primero;
            }
            
            if (j - i + 1 > l) {
                l = j - i + 1;
                izq = i;
                der = j;
            }

            if (lu[j] == 1) ultimoUno = j;
        }

        for (ll i = 0; i < n; i++)
        {
            if (lu[i] == -1) lu[i] = 0;
        }

        if (l > 0) {
            lu[izq] = 1;
            lu[der] = 1;
        }

        for (ll i = 0; i < n; i++)
        {
            cout << lu[i] << " ";
        }
        cout << endl;
    }
    return 0;
}