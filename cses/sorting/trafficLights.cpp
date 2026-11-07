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

    ll x,n; cin>>x>>n;

    set<pair<ll,ll>> rangos;

    multiset<ll> lu;


    rangos.insert({0,x});

    lu.insert(x);

    for (ll i = 0; i < n; i++)
    {
        ll poste; cin>>poste;
        auto it = rangos.lower_bound({poste,-1});

        it--;

        auto [a,b] = *it;

        auto it2 = lu.find(b-a);

        lu.erase(it2);


        pair<ll,ll> rango1 = {a,poste}; 
        pair<ll,ll> rango2 =  {poste,b};
        rangos.insert(rango1);
        rangos.insert(rango2);
        rangos.erase(it);
        lu.insert(poste-a);
        lu.insert(b-poste);
        
        cout<<*lu.rbegin()<<" ";
    }
    
    


    return 0;
}