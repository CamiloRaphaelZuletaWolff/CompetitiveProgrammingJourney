#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU {
private:
    map<int, int> p;
    vector<int> rank;
    int numSets;
public:
    DSU(int n) {
        for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        numSets = n;
        p[-1] = -1;
        p[-2] = -2;
    }

    int findSet(int i) {
        return (p[i] == i) ? i: (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    int numDisjointSets() {
        return numSets;
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        --numSets;
    }
};

bool dfs(ll x, ll p, map<ll,set<ll>> &grafo, map<ll,ll> &col){
    if(col[x] == 0){
        col[x] = col[p]==1?2:1;
    }else{
        if(col[x] == col[p]){
            return false;
        }
        return true;
    }
    bool f = 1;
    for(auto &a:grafo[x]){
        f&= dfs(a,x,grafo,col);
        if(!f)break;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, m; cin >>n >>m;

    DSU dsu = DSU(n);

    vector<bool> vis(n);
    vector<pair<int, int>> nop;
    while (m--) {
        int t, a, b; cin >> t >> a >> b;
        --a, --b;
        vis[a] = vis[b] = true;
        if (t == 1) {
            dsu.unionSet(a, b);
        } 
        else nop.push_back({a, b});
            
    }

    bool f = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     f&=vis[i];
    // }
    // if(!f){
    //     cout<<-1<<"\n";
    //     return 0;
    // }    
    map<ll,set<ll>> grafo;
    map<ll,ll> col;
    for (int i = 0; i < nop.size(); i++)
    {
        auto [x,y] = nop[i];
        grafo[dsu.findSet(x)].insert(dsu.findSet(y));
        grafo[dsu.findSet(y)].insert(dsu.findSet(x));
    }
    for (int i = 0; i < n; i++)
    {
        col[dsu.findSet(i)]= 0;
    }
    // vector<ll> viss(n);
    // for(auto [k,v]:grafo){
    //     for(auto x:v){
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(auto &[k,v]:col){
        if(v==0){
            v =1;
            for(auto &x:grafo[k]){
                f&=dfs(x,k,grafo,col);
            }
        }
        if(!f)break;
    }
    if(f){
        for (int i = 0; i < n; i++)
        {
            cout<<col[dsu.findSet(i)]<<" ";
        }
        cout<<"\n";
    }else{
        cout<<"-1\n";
    }


    return 0;

}