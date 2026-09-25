#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


vector<ll> numeritos;

ll a,b;

ll cantidadDeHeroes(ll l, ll r){

    auto it = lower_bound(numeritos.begin(), numeritos.end(), l);
    auto it2 = upper_bound(numeritos.begin(), numeritos.end(), r);
    return it2 - it;

}

ll f (ll l, ll r){
    
    ll heroes = cantidadDeHeroes(l,r);
    

    if(heroes == 0){
        return a;
    }
    
    if(l == r){
        return b * heroes; 
    }

    ll quemarTodo = (r - l + 1) * b * heroes;

    ll medio = (l+r)/2;
    ll res =min(quemarTodo, f(l,medio) + f(medio+1,r));
    
    // cout<<l<<" "<<r<<" "<<heroes<<" "; cout<<res<<"\n"; 
    return min(quemarTodo, res);
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,k; cin>>n>>k>>a>>b;

    for (ll i = 0; i < k; i++)
    {
        ll x; cin>>x;
        numeritos.push_back(x);

    }

    sort(numeritos.begin(), numeritos.end());

    ll res = f(1LL , 1LL << n);

    cout<<res;


    

    
    



    return 0;

}