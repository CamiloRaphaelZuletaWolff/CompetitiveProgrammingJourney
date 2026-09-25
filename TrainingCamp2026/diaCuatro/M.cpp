#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    set<ll> setcito;
    vector<ll> numeritos;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        numeritos.push_back(x);
    }

    sort(numeritos.begin(),numeritos.end());

    ll contador =0;
    ll tiempo = 0;

    for (ll i = 0; i < numeritos.size(); i++)
    {
        if(tiempo <= numeritos[i]){
            contador ++;
            tiempo += numeritos[i];
        }
    }

    cout<<contador;
    



    

    
    

    return 0;

}