#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,k,c;cin>>n>>k>>c;
    map<ll,ll> mp;
    vector<pll> pares(n);
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    for (int i = 0; i < n; i++)
    {
        auto &[a,b] = pares[i];
        cin>>a>>b;
    }
    vll vis(n);
    for (int i = 0; i < n && k; i++)
    {
        auto [a,b] = pares[i];
        if(mp[b] == c)continue;
        mp[b]++;
        vis[i]= 1;
        pq.emplace(i+1, a);
        k--;
    }
    for (int i = 0; i < n && k; i++)
    {
        if(vis[i] == 0){
            pq.emplace(i+1,pares[i].first);
            k--;
        }
    }
    for (; !pq.empty();)
    {
        cout<<pq.top().second<<endl;
        pq.pop();
    }
    
    

    return 0;

}