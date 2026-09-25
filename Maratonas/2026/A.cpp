#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n;cin>>n;

    vector<ll>prefixC(n+1,0), prefixV(n+1,0);

    for (ll i = 1; i <= n; i++)
    {
        ll c,v; cin>>c>>v;

        prefixC[i] = prefixC[i-1] + c;
        prefixV[i] = prefixV[i-1] + v;

    }

    ll q; cin>>q;

    for (ll i = 0; i < q; i++)
    {
        ll x ;cin>>x;
        ll numerador = prefixC[x] - prefixV[x];
        
        if(numerador == 0){
            cout<<"NEUTRO"<<endl;
            continue;

        }
        if(numerador < 0){
            cout<<"VENDA"<<endl;
            continue;
        }
        

        cout<<"COMPRA"<<endl;
    }
    
    

    return 0;

}