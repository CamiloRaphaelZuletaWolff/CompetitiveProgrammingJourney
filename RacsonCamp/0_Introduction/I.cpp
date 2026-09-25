#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    ll t; 
    if (cin >> t) {
        while (t--) {
            ll s, t_val; 
            cin >> s >> t_val;
            
            ll primerPar = s, primerImpar = s;
            ll ultimoPar = t_val, ultimoImpar = t_val;

            if (s % 2 == 0) {
                primerImpar++;
            } else {
                primerPar++;
            }

            if (t_val % 2 == 0) {
                ultimoImpar--;
            } else {
                ultimoPar--;
            }

            ll nPares = 0, nImpares = 0;
            ll totalPares = 0, totalImpares = 0;

            if (primerPar <= ultimoPar) {
                nPares = (ultimoPar - primerPar) / 2 + 1;
                totalPares = nPares * (primerPar + ultimoPar) / 2;
            }

            if (primerImpar <= ultimoImpar) {
                nImpares = (ultimoImpar - primerImpar) / 2 + 1;
                totalImpares = nImpares * (primerImpar + ultimoImpar) / 2;
            }

            cout << totalPares - totalImpares << "\n";
        }
    }
    return 0;
}