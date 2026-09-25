#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX / 4;

struct nodo{
    ll hijo;
    ll fibra;
    ll microonda;
};

struct elemento
{
    ll distancia;
    ll nodo;
    ll usados;

    bool operator<(const elemento a) const {

        return distancia > a.distancia;
    
    }

};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<nodo>> g(n+1);   // g[u] = {vecino, peso}
    for(ll e = 0; e < m; e++){
        ll u, v; ll w, f;
        cin >> u >> v >> w>>f;
        g[u].push_back({v, w, f});
        g[v].push_back({u, w, f});
    }

    vector<vector<ll>> dist(n+1, vector<ll>(k+2,INF));
    priority_queue<elemento> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while(!pq.empty()){

        elemento top = pq.top(); pq.pop();
        
        ll d = top.distancia; ll u = top.nodo;
        ll usados = top.usados;
        
        if(d > dist[u][usados]) continue;              // descarte perezoso
        
        for(size_t idx = 0; idx < g[u].size(); idx++){
        
            ll v = g[u][idx].hijo;
        
            ll w = g[u][idx].fibra;

            ll f = g[u][idx].microonda;
            
            if(f == -1){
                f = INF;
            }
        
            if(d + w < dist[v][usados]){
        
                dist[v][usados] = d + w;
        
                pq.push({dist[v][usados], v,usados});
            }
            
            if(d + f  < dist[v][usados+1] && usados <= k){
        
                dist[v][usados+1] = d + f;
                pq.push({dist[v][usados+1], v,usados+1});
            }

            
        }
    }
    ll lu = LLONG_MAX; 

    for (ll i = 0; i <= k; i++)
    {
        lu = min(lu, dist[n][i]);
    }
    cout<<lu<<endl;
    return 0;
}