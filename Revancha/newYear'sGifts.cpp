#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct amigo
{
    ll caja;
    ll regalo;
    ll minimo;
    ll ahorro;

    bool operator <(const amigo a) const {
        if(caja == a.caja){
            if(minimo == a.minimo){
                return ahorro > a.ahorro;
            }else{
                return minimo < a.ahorro;
            }
        }else{
            return caja < a.caja;
        }
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){

        ll n,m,k; cin>>n>>m>>k;

        vector<ll> cajas;

        for (ll i = 0; i < m; i++)
        {
            ll x; cin>>x;
            cajas.push_back(x);
        }
        
        sort(cajas.begin(), cajas.end());


        vector <amigo> amiguitos;
        
        for (ll i = 0; i < n; i++)
        {
            ll a,b,c; cin>>a>>b>>c;

            amiguitos.push_back({a,b,c, c-b});
        }

        
        


        





        
    }

    return 0;

}