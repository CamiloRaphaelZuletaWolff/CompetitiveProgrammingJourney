#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    set<pair<ll,ll>> setsito;

    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        setsito.insert({a,i});
    }

    ll target = 0LL;
    
    auto it = setsito.upper_bound({target,0LL});
        
    auto [previo,i] = *it;
    
    setsito.erase(it);

    target++;
    ll lu = 1;
    while (!setsito.empty())
    {
        auto it2 = setsito.upper_bound({target,0LL});
        
        auto [actual,index] = *it2;
        // cout<<actual<<" "<<index<<endl;
        if(index < i){
            lu++;
        }
        previo = actual;
        i = index;
        target++;

        setsito.erase(it2);
    }

    cout<<lu<<endl;
    





    
    
    

    return 0;
}