#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n ; cin >>n;
    
 
    map<ll,ll> parejitas;
 
    set<ll> apariciones;
 
    ll lu = 0;
    
    ll esperado = 1;
 
    ll index = 0;
 
    vector<ll> numeritos;
 
    vector<bool> vis(n,0);
 
    for (ll i = 0; i < n; i++)
    {
        ll actual; cin>>actual;
        numeritos.push_back(actual);
        
        if(!apariciones.count(actual)){
            apariciones.insert(actual);
            parejitas[actual] = i;
            lu += apariciones.size();
            continue;
 
        }
        for (ll j = parejitas[actual]; j >= 0; j--)
        {
            if(vis[j]) break;
            apariciones.erase(numeritos[j]);
            vis[j] = true;
        }
        parejitas[actual] = i;
        apariciones.insert(actual);
        lu += apariciones.size();
    }
 
    cout<<lu;
 
 
    
    
    return 0;
}
