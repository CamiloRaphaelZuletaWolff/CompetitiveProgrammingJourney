#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n;
    while(cin>>n && n != 0){

        vector<ll> numeritos(n,0);

        for (ll i = 0; i < n; i++)
        {
            cin>>numeritos[i];
        }

        vector<ll> menorIzq(n,0);
        vector<ll> menorDer(n,0);

        menorIzq[0] = numeritos[0];

        for (ll i = 1; i < n; i++)
        {
            menorIzq[i] = min(menorIzq[i-1], numeritos[i]);
        }

        menorDer[n-1] = numeritos[n-1];
        for (ll i = n-2; i >= 0; i--)
        {
            menorDer[i] = min(menorDer[i+1], numeritos[i]);
        }

        ll lu = 0;

        for (ll i = 0; i < n; i++)
        {
            ll pared = max(menorIzq[i], menorDer[i]);
            lu += numeritos[i] - pared;
        }
        
        cout<<lu<<endl;
        
    }

    return 0;

}