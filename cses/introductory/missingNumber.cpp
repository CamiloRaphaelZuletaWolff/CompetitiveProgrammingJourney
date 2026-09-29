#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    map<ll,ll> mapita;

    for (ll i = 1; i <= n; i++)
    {
        mapita[i] = 0;
    }
    

    for (ll i = 0; i < n-1; i++)
    {
        ll x; cin>>x;
        mapita[x]++;
    }

    for(auto [a,b] : mapita){
        if(b == 0) {
            cout<<a; 
            break;
        }
    }

    
    

    return 0;

}