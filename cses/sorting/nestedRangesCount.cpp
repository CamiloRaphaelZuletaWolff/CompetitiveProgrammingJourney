#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick(int n) : n(n), t(n + 1, 0) {}
    void add(int i, ll v) { for (; i <= n; i += i & -i) t[i] += v; }
    ll sum(int i) { ll s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
};




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;

    vector<tuple<ll,ll,ll>> rangos;
    
    vector<ll> derecha;

    for (ll i = 0; i < n; i++)
    {
        ll a, b; cin>>a>>b;
        rangos.push_back({a,b,i});
        derecha.push_back(b);
    }

    vector<ll> lu1(n,0);
    vector<ll> lu2(n,0);

    sort(rangos.begin(),rangos.end(), [] (tuple<ll,ll,ll> a1, tuple<ll,ll,ll> b1){
        auto [a,b,c] = a1;
        auto [d,e,f] = b1;
        return a == d ? b > e : a < d;
    });

    auto getId = [&](ll v) {
        return int(lower_bound(derecha.begin(), derecha.end(), v) - derecha.begin()) + 1;
    };

    sort(derecha.begin(), derecha.end());
    derecha.erase(unique(derecha.begin(), derecha.end()), derecha.end());

    Fenwick fw(derecha.size());
    ll contador = 0;
    for (ll i = n-1; i >= 0; i--) {  

        auto [a,b,c] = rangos[i];
        ll id = getId(b);
        ll cuantos = fw.sum(id);
        lu1[c] = cuantos;
        
        fw.add(id, 1);
        
    }

    
    Fenwick fw2(derecha.size());
    for (ll i = 0; i < n; i++)
    {
        
        auto [a,b,c] = rangos[i];
        ll id = getId(b);
        lu2[c] = contador - fw2.sum(max(id-1,0LL));
        contador++;
        fw2.add(id, 1);     
        
    }
    

    for(auto a : lu1){
        cout<< a<<" ";
    }
    cout<<endl;
    for(auto a : lu2){
        cout<< a<<" ";
    }
    cout<<endl;
    
    

    return 0;
}