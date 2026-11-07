#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,target;cin>>n>>target;

    vector<ll> numeritos;

    vector<ll> prefix(n+1,0);

    map<ll,ll> mapita;


    for (ll i = 1; i <= n; i++)
    {
        ll a; cin>>a;
        
        prefix[i] = prefix[i-1] + a;
        numeritos.push_back(a);
    }
    ll lu = 0;

    for (ll i = 0; i <= n; i++)
    {
        
        ll x = prefix[i]-target;
        lu += mapita[x];
        mapita[prefix[i]]++;
        
    }



    
    cout<<lu;
    




    
    return 0;
}