#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> bfs(ll inicio, map<ll, vector<ll>> &grafo, map<ll, ll> soldiers){

    queue<pair<ll,ll>> colita;
    map<ll, ll> dist;
    colita.push({inicio, 1});
    dist[inicio] = 1;
    while(!colita.empty()){
        auto [actual,nivel] = colita.front(); colita.pop();
        for (ll i = 0; i < grafo[actual].size(); i++) {
            ll vecino = grafo[actual][i];
            if(dist.find(vecino) == dist.end()){
                dist[vecino] = dist[actual] + 1;
                colita.push({vecino,nivel+1});
            }   
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin >> n;
    map<ll, vector<ll>> grafo;
    map<ll, ll> soldiers;

    for (ll i = 1; i < n; i++) {
        cin >> soldiers[i];
    }

    for (ll i = 1; i < n; i++) {
        ll v, u; cin >> u >> v;
        --u, --v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    pair<ll,ll> lu = {1e9, -1};
    for (ll i = 0; i < grafo[0].size(); i++) {
        pair<ll,ll> res = bfs(grafo[0][i], grafo, soldiers);

        if(lu.first <= res.first){
            if(lu.first == res.first){
                lu.second = min(res.second,lu.second);
            }
            lu.first = res.first;
        }
    }
    cout << lu.second << ' ' << lu.first << '\n';

    return 0;
}