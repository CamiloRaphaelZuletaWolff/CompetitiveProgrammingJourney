#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct par {
    ll a;
    ll b;


    bool operator<(const par& x) const {
        return a < x.a;
    }
};

int main(){
    ll n, k; cin >> n >> k;
    //priority_queue<pair<ll, ll>> colita;
    priority_queue<par> colita;

    while (n--){
        ll a, b; cin >> a >> b;
        par p = {b,a};
        //colita.push({a,b});
        colita.push(p);
    }

    ll contador=0;
    ll res = 0;
    //pair<ll, ll> aux;
    par aux2;
    while(contador != k){
        
        res += colita.top().a;
        //cout << res << endl;
        //aux = {colita.top().b-colita.top().a,0};
        aux2 = {colita.top().b-colita.top().a,0};
        //cout << to_string(aux.first) << endl;
        //cout << to_string(aux.second) << endl;
        colita.pop();
        //colita.push(aux);
        colita.push(aux2);
        contador++;
    }
    cout << res << endl;

}