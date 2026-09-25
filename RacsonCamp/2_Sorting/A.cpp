#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll x; cin>>x;

    vector<ll> vectorcito;

    for (ll i = 0; i < x; i++)
    {
        ll a; cin>>a;
        vectorcito.push_back(a);
    }

    sort(vectorcito.begin(), vectorcito.end());

    for (ll i = 0; i < x; i++)
    {
        cout<< vectorcito[i] << " ";
    }
    
    

    return 0;

}