#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k, p; cin >> n >> k >> p;
    ll aux = 1;
    vector<ll> div;
    vector<ll> res;
    for (ll i = 0; aux*aux <= n; i++){
        if (n%aux==0){
            div.push_back(aux);
            if(n/aux != aux){
                div.push_back(n/aux);
            }
        }
        aux++;
    }
    
    for (ll i = 0; i < div.size(); i++){
        if(div[i]>k){
            continue;
        }
        if (n/div[i]<=p){
            res.push_back(div[i]);
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}