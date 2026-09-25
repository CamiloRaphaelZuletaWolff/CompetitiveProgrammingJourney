#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n; cin>>n;
    vector<ll>numeritos;

    ll contadorY= 0;

    for (ll i = 0; i < 2*n; i++)
    {
        ll x, y; cin>>x>>y;

        contadorY+= y;

        numeritos.push_back(x+y);
    }

    sort(numeritos.begin(),numeritos.end(), greater<ll>());

    ll contadorX = 0;

    for (ll i = 0; i < n; i++)
    {
        contadorX+= numeritos[i];
    }

    cout<<contadorX - contadorY;
    


    

    return 0;

}