#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
 
    ll n,m; cin>>n;
    cin>>m;
    vector<pair<ll,ll>> numeritos;

    vector<ll> pos;
    
    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        pos.push_back(a);
        numeritos.push_back({a,i});    
    }

    sort(numeritos.begin(),numeritos.end());


    vector<pair<bool,bool>> estados(n,{true,true});

    ll lu =1;

    auto [previo,index] = numeritos[0];
    
    for (ll i = 1; i < n; i++)
    {
        auto [actual,indice] = numeritos[i];

        if(indice < index){
            estados[actual-1] = {false, estados[actual-1].second};
            estados[previo-1] = {estados[previo-1].second, false};
            // estados[i] 
            lu++;
        }
        previo = actual;
        index = indice;
    }

    for (ll i = 0; i < m; i++)
    {
        ll l,r; cin>>l>>r;
        l--;r--;

        ll numeroL = pos[l];
        ll numeroR = pos[r];
        



        



        
    }
    

    
 
 
 
 
 
    
    
    
 
    return 0;
}