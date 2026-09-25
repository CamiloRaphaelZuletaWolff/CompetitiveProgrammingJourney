#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;



struct punto{

    ll x;
    ll y;

};

vector<punto> puntitos;

vector<ll> prefix;

ll f(ll l, ll r){

    if(r == l) return LLONG_MAX;

    if((r-l+1) == 2) return (puntitos[l].x-puntitos[r].x)*(puntitos[l].x-puntitos[r].x) + (puntitos[l].y-puntitos[r].y)*(puntitos[l].y-puntitos[r].y);
    
    ll mid = (r+l)/2;

    ll izquierda = f(l,mid);
    ll derecha = f(mid+1,r);

    ll d = min(izquierda,derecha);

    vector<punto> seleccionados;

    for (ll i = l; i <= r; i++)
    {
        if((mid - puntitos[i].x)*(mid - puntitos[i].x) < d ){
            seleccionados.push_back(puntitos[i]);
        }
    }

    sort(seleccionados.begin(),seleccionados.end(), [](punto a, punto b){
        return a.y>b.y;
    });

    for (ll i = 0; i < seleccionados.size(); i++)
    {
        for (ll j = i+1; j < seleccionados.size(); j++)
        {
            if(_abs64((seleccionados[i].y - seleccionados[j].y)* (seleccionados[i].y - seleccionados[j].y)) > d) break;
            
            d = min(d, (seleccionados[i].x -seleccionados[j].x)*(seleccionados[i].x - seleccionados[j].x) + (seleccionados[i].y - seleccionados[j].y)*(seleccionados[i].y - seleccionados[j].y) );
        }
    }

    return d;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    prefix.push_back(0LL);

    for (ll i = 1; i <= n; i++)
    {
        ll x; cin>>x;

        prefix.push_back(prefix[i-1] + x);
    }

    puntitos.push_back({-5000000000000,-500000000000});

    for (ll i = 1; i <= n; i++)
    {

        puntitos.push_back({i,prefix[i]});
        
    }

    cout<<f(1,n);


    
    




    
    
    
    return 0;

}