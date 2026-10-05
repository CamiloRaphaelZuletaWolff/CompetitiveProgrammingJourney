#include <bits/stdc++.h>
using namespace std;

typedef int ll;

vector<int> menor;
vector<int> primos;

void criba(ll n) {
    menor.assign(n + 1, 0);
    primos.clear();

    for (ll i = 2; i <= n; i++) {
        if (menor[i] == 0) {
            menor[i] = i;
            primos.push_back(i);
        }

        for (ll p : primos) {
            if (p > menor[i] || 1LL * i * p > n) break;
            menor[i * p] = p;
        }
    }
}

vector<pair<ll, ll>> factorizar(ll x) {
    vector<pair<ll, ll>> factores;
    while (x > 1) {
        ll p = menor[x];
        ll cantidad = 0;

        while (x % p == 0) {
            x /= p;
            cantidad++;
        }

        factores.push_back({p, cantidad});
    }
    return factores;
}


int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);


    
    ll n,q; cin>>n>>q;

    criba(n);

    vector<pair<vector<ll>,ll>> lu;
    
    for (ll i = 1; i <= n; i++)
    {

        vector<ll> aux;
        aux.push_back(0LL);
        
        ll aux2 = i;
        
        while(aux2 > 1){
            aux.push_back(menor[aux2]);
            aux2/=menor[aux2];
        }


        lu.push_back({aux,i});
    }

    sort(lu.begin(), lu.end());

    while(q--){
        ll x; cin>>x;
        if(x == 1) {
            cout<<1<<endl;
            continue;
        }

        cout << lu[x-1].second<<endl;
    }
    




    return 0;
}