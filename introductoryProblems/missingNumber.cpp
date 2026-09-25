#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    ll n;
    cin>>n;

    ll contador = 0;
    for (ll i = 1; i < n; i++)
    {
        ll x;cin>>x;
        contador += x;

    }

    n = (n*(n+1))/2;

    cout<<n-contador;

    

    return 0;

}