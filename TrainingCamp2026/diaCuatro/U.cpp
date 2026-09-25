#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,k;cin>>n>>k;
    
    map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll a;cin>>a;
        mp[a]++;
    }
    auto be = mp.begin();
    auto en = mp.end();
    en--;
    while(k && be->first <= en->first){
    //     for(auto [y,z]:mp){
    //     cout<<y<<" "<<z<<"\n";
    // }
        if(be->second < en->second){
            if(be->second<=k){
                ll aux = max(0LL,k-be->second);
                auto [ke,v] = *be;
                mp.erase(be);
                mp[ke+1]+=v;
                k=aux;
                be = mp.begin();
            }else{
                break;
            }
        }else{
            if(en->second<=k){
                ll aux = max(0LL,k-en->second);
                auto [ke,v] = *en;
                mp.erase(en);
                mp[ke-1]+=v;
                k=aux;
                en =mp.end();
                en--;
            }else{
                break;
            }
        }
    }
    
    be = mp.begin();
    en = mp.end();
    en--;
    ll res = en->first - be->first;
    cout<<res<<"\n";  
    return 0;

}