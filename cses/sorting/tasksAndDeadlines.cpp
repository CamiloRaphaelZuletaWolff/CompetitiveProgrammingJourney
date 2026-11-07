#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n;cin>>n;

    vector<pair<ll,ll>> tiempos;

    for (ll i = 0; i < n; i++)
    {
        ll a,b;cin>>a>>b;
        tiempos.push_back({a,b});
    }

    sort(tiempos.begin(),tiempos.end());


    ll lu = 0;
    ll contador = 0;


    for (ll i = 0; i < n; i++)
    {
        auto [a,b] = tiempos[i];
        contador += a;         
        lu += b - contador;

    }

    cout<<lu;
    

    return 0;
}