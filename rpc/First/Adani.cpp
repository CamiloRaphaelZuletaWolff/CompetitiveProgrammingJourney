#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k, c; cin >> n >> k >> c;
    vector<pair<ll, ll>> pares;
    vector<ll> equipos(n+1);
    vector<ll> res;
    vector<bool> pass(n+1);

    while(n--){
        ll a, b; cin >> a >> b;
        pares.push_back({b, a});
    }

    ll aux = 0;
    for (ll i = 0; i < pares.size(); i ++){
        if(aux==k){
            break;
        }
        equipos[pares[i].first]++;
        if (equipos[pares[i].first]>c){
            continue;
        }
        aux++;
        pass[i] = true;
    }
    if (aux != k){
        for (ll i = 0; i < pares.size(); i++){
            if (aux == k){
                break;
            }
            if (!pass[i]){
                pass[i] = true;
                aux++;
            }
        }
    }

    for (ll j = 0; j < pares.size(); j ++){
        if (pass[j]){
            cout << pares[j].second << endl;
        }
    }
    
}