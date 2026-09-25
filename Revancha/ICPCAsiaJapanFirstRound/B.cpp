#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n,d;
    while(cin>>n>>d && n != 0 && d != 0){
        vector<int> puertas;
        for(ll i = 0; i < n; i++){
            ll p; cin >> p;
            puertas.push_back(p);
        }
        ll acc = 1;
        bool cubre = false;
        if (puertas.size()==1){
            cout << 1 << endl;
            continue;
        } 
        bool fin = false;
        
        ll rango = puertas[0] + 2*d;
        for (ll i = 0; i < puertas.size(); i++)
        {
            if (puertas[i] > rango){
                acc++;
                rango = puertas[i] + 2*d;
            }
        }
        cout << acc << endl;
        

        
    }

    return 0;

}