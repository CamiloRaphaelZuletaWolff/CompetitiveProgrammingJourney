#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll fuerza(ll c) {
    if (c == 2) return 15;
    if (c == 1) return 14;
    return c;             
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    map<string,ll> repetidos;

    ll n; cin>>n;

    ll a = 0, b = 0;
    ll contador = 0, aux = 0;


    for (ll i = 1; i <= n; i++)
    {
        ll x;cin>>x;

        if(x %2 == 0){
            a = i;
            contador++;
        }else{
            b=i;
            aux++;
        }

    }

    
        if(contador == 1){
            cout<<a<<endl;
        }else{
            cout<<b<<endl;
        }
    return 0;

}