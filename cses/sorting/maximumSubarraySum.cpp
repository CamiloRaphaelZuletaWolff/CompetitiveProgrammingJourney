#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;
    
    vector<ll> numeritos;

    for (ll i = 0; i < n; i++)
    {
        ll x ; cin>>x;
        numeritos.push_back(x);
    }


    ll lu = numeritos[0], aux = numeritos[0];

    for (ll i = 1; i < n; i++)
    {
        aux = max(numeritos[i], aux + numeritos[i]);
        lu = max(lu,aux);
    }

    cout<<lu<<endl;
    
    
    

    return 0;
}