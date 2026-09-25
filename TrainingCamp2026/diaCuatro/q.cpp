#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll pow(ll b,ll e){
    ll res = 1;
    for (int i = 0; i < e; i++)
    {
        res*=b;
    }
    return res;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n,m; cin>>n>>m;
    multiset<ll> mt;
    for (int i = 0; i < n; i++)
    {
        ll a;cin>>a;
        mt.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        ll a;cin>>a;
        auto p = mt.upper_bound(a);
        if(p == mt.begin()){cout<<-1<<'\n';continue;}
        p--;
        cout<<*p<<"\n";
        mt.erase(p);
    }
    
        
    // cout<<"\n";    
    

    return 0;

}