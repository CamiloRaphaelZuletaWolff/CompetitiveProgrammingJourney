#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e15;

vector<ll> dijkstra(ll s, ll t, const vector<map<ll, ll>> &adj) {
    ll n = adj.size();

    vector<ll> dist(n, INF);
    vector<ll> parent(n, -1);

    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF) return {};

    vector<ll> path;

    for (ll v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n, m,k,s,d;
    cin>>n>>m>>k>>s>>d;

    vector<map<ll, ll>> adj(n);

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        --u;
        --v;

        adj[u][v] = w;
        adj[v][u] = w;
    }

    ll lu = 0;
    vector<ll> camino;

    s--; d--;


    for (ll i = 0; i < k; i++)
    {
        lu = 0;
        
        camino = dijkstra(s, d, adj);    

        ll anterior = s;

        for (ll i = 1; i < camino.size(); i++)
        {
            ll actual = camino[i];

            lu += adj[anterior][actual];
            adj[anterior][actual] = INF;
            adj[actual][anterior] = INF;

            anterior = actual;
        }      

    }

    cout<< lu << endl;
    for (ll i = 0; i < camino.size(); i++)
    {
        if(i != 0) cout<<" - ";
        cout<<camino[i]+1;
    }

    cout<<endl;    


}