#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll L, R;                  
vector<vector<ll>> adj;   
vector<ll> matchR;        
vector<bool> vis;

bool tryKuhn(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (matchR[v] == -1 || tryKuhn(matchR[v])){
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    matchR.assign(R, -1);
    int res = 0;
    for (int u = 0; u < L; u++) {
        vis.assign(R, false);
        if (tryKuhn(u)) res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,m1,m2; cin>>n>>m1>>m2;


    if(m1!=m2) {
        cout<<-1<<endl;
        return 0;
    }
    set<pair<ll,ll>> actual, deseada;

    vector<pair<ll,ll>> izquierda(m1), derecha(m2);

    for (ll i = 0; i < m1; i++) {
        ll u, v; cin >> u >> v;

        if (u > v) swap(u, v);
        
        izquierda[i] = {u, v};
        
        actual.insert({u, v});
    }

    for (ll i = 0; i < m2; i++) {
        
        ll u, v; cin >> u >> v;
        
        if (u > v) swap(u, v);
        
        derecha[i] = {u, v};
        
        deseada.insert({u, v});
    }

    vector<pair<ll,ll>> sobrantes, faltantes;

    for (auto e : izquierda){

        if (!deseada.count(e)) sobrantes.push_back(e);
    
    }
    for (auto e : derecha){
    
        if (!actual.count(e)) faltantes.push_back(e);
    
    }

    L = sobrantes.size();
    R = faltantes.size();

    adj.assign(L, {});

    for (ll i = 0; i < L; i++) {
        auto [a, b] = sobrantes[i];
        for (ll j = 0; j < R; j++) {
            auto [c, d] = faltantes[j];
            if (a == c || a == d || b == c || b == d)
                adj[i].push_back(j);
        }
    }

    ll lu = maxMatching();

    // cout<<lu<<endl; 

    // cout<<sobrantes.size()<<endl;

    // cout<<faltantes.size()<<endl;

    cout<< 2*sobrantes.size() -lu;


    return 0;

}