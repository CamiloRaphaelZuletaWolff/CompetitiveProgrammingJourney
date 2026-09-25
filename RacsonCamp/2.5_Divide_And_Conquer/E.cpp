#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll t;

vector<ll> prefix;

ll f(ll l, ll r){

    if(l == r) return prefix[r] - prefix[l-1] < t;

    ll res = 0;

    ll mid = (r+l)/2;

    res += f(l,mid);

    res += f(mid+1,r);

    vector<ll> seleccionados;

    for (ll i = l; i <= mid; i++)
    {
        seleccionados.push_back(prefix[i-1]);
    }

    sort(seleccionados.begin(),seleccionados.end());

    for (ll i = mid+1; i <= r; i++)
    {
        auto it = upper_bound(seleccionados.begin(),seleccionados.end(),prefix[i]-t);

        res += seleccionados.end()-it;


    }
    

    


    return res;

}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n>>t;

    prefix.push_back(0LL);

    for (ll i = 1; i <= n; i++)
    {
        ll x; cin>>x;

        prefix.push_back(prefix[i-1] + x);
    }

    cout<<f(1,n);


    
    




    
    
    
    return 0;

}