#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n,k; cin>>n;

    map<ll,ll> mapita;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        mapita[x]++;
        
    }
    ll res = 0;
    for(auto a : mapita){
        ll clave = a.first;
        ll valor = a.second;
        if(valor >= clave){
            res += abs(clave - valor);
        }else{
            res+= valor;
        }
    }

    cout<<res;
    

    

    return 0;

}