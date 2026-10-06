#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<pair<ll,ll>> rangos;


    for (ll i = 0; i < n; i++)
    {
        ll a,b; cin>>a>>b;
        rangos.push_back({a,1});
        rangos.push_back({b,-1});
    }
    sort(rangos.begin(), rangos.end());
    ll lu = 0;
    ll aux =0;

    for (ll i = 0; i < 2*n; i++)
    {
        aux+= rangos[i].second;
        lu = max(aux,lu);
    }

    cout<<lu;
    
    

    
    
    

    


    return 0;
}