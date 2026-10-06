#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,m; cin>>n>>m;

    multiset<ll> ms;


    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;

        ms.insert(x);
    }

    for (ll i = 0; i < m; i++)
    {
        ll cliente; cin>>cliente;

        auto it = ms.lower_bound(cliente);

        ll actual = -1;

        if(it != ms.end()){
            actual = *it;

        }

        if(actual == cliente){
            cout<<actual<<endl;
            ms.erase(it);
            continue;
        }

        if(it == ms.begin()) {
            cout<<-1<<endl;
            continue;
        }

        it--;

        actual = *it;

        if(actual <= cliente){
            cout<<actual<<endl;
            ms.erase(it);
        }else{
            cout<<-1<<endl;
        }





    }
    
    
    
    

    return 0;
}