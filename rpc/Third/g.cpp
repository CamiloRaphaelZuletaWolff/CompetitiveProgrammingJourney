#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool dfs(ll nodo,vector<ll>& R,vector<ll>& B, vector<ll>& vis, vector<vector<pair<ll,ll>>>& grafo, vector<ll>& pa){

    for(auto [w,ni]:grafo[nodo]){
        if(vis[ni]){
            if(pa[nodo]==ni)continue;
            ll r = R[nodo]-R[pa[ni]];
            ll b = B[nodo]-B[pa[ni]];
            if(r == 1 || b == 1){
                return false;
            }
        }else{
            // cout<<ni<<" ";
            vis[ni] = 1;
            R[ni] = R[nodo]+(w==1);
            B[ni] = B[nodo]+(w==0);
            pa[ni] = nodo;
            bool f = dfs(ni,R,B,vis,grafo,pa);
            if(!f)return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,m;cin>>n>>m;
    vector<vector<pair<ll,ll>>> arr(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a,b,w;cin>>a>>b>>w;
        a++,b++;
        arr[a].push_back({w,b});
        arr[b].push_back({w,a});
    }
    vector<ll> R(n+1);
    vector<ll> B(n+1);
    vector<ll> pa(n+1);
    vector<ll> vis(n+1);
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            pa[i] = 0;
            vis[i] = 1;
            f = dfs(1,R,B,vis,arr,pa);
            // cout<<"\n";
            if(!f)break;
        }
    }
    cout<<(f?"YES\n":"NO\n");

    // cout<<"\n";
    // for(auto r:R)cout<<r<<" ";coust<<"\n";
    
    return 0;

}