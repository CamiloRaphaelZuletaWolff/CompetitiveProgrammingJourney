#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

ll res = 1;

vector<set<ll>> restricciones (200000+1);

void topoSort(vector<vector<int>>& adj) {
    int n = adj.size();                 
    vector<int> indegree(n, 0);
    queue<int> q;

    for (int i = 1; i < n; i++) {
        for (int next : adj[i])
            indegree[next]++;
    }

    for (int i = 1; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<ll> ready(n, 1);
    ll tomados = 0;
    while (!q.empty()) {

        int top = q.front();
        q.pop();
        tomados++;

        ll s = ready[top];
        while (restricciones[top].count(s)) s++;   

        res = max(res, s);

        for (int next : adj[top]) {
            ready[next] = max(ready[next], s + 1);
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (tomados < n - 1) res = -1;      
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for (ll i = 0; i < m; i++)
    {
        ll u,v; cin>>u>>v;
        addEdge(adj,u,v);
    }

    ll k; cin>>k;

    for (ll i = 0; i < k; i++)
    {
        ll j,x; cin>>j>>x;
        restricciones[x].insert(j);
    }

    topoSort(adj);

    cout<<res;
}