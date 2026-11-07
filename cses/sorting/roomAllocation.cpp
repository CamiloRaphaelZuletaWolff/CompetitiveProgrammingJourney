#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;
 
    vector<tuple<ll,ll,ll>> clientes;
 
    for (ll i = 0; i < n; i++)
    {
        ll a,b; cin>>a>>b;
 
        clientes.push_back({a,b,i});
    }
 
    sort(clientes.begin(), clientes.end());
 
    multiset<pair<ll,ll>> lu;
 
 
    vector<ll> habitacion(n);
 
    ll conteo = 0;
 
    for (ll i = 0; i < n; i++)
    {
        auto [inicio, final,index] = clientes[i];
 
        auto it = lu.lower_bound({inicio,-1});
 
        if(it == lu.begin()){
            // cout<<"Nueva "<<inicio<<" "<<final<<" "<<index<<endl;
            conteo++;
            habitacion[index] = conteo;
            lu.insert({final,conteo});
        }else{
            
            // cout<<"Reuso "<<inicio<<" "<<final<<" "<<index<<endl;
            it--;
            auto [a,b] = *it;
 
            // cout<<a<<" "<<b<<endl;
            lu.erase(it);
            lu.insert({final,b});
            habitacion[index] = b;
        }
 
    }
 
    cout<<lu.size()<<endl;
    for (ll i = 0; i < n; i++)
    {
        cout<<habitacion[i]<<" ";
    }
    
    
 
 
    
 
 
    return 0;
}