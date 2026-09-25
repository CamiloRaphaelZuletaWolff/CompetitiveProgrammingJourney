#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


ll MOD = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,a,b,primero; cin>>n>>a>>b>>primero;

    vector<ll> numeritos(MOD+5,0);

    ll previo = primero;

    for (ll i = 0; i < n; i++)
    {
        ll x= ((a)*(previo)+b)%(MOD) +1;
        numeritos[x]++;
        previo = x;
    }
    
    for (ll i = 0; i < numeritos.size()-1; i++)
    {
        for (ll j = 0; j < numeritos[i]; j++)
        {
            cout<<i<<" ";
        }
        
        
    }
    
    
    
    return 0;

}