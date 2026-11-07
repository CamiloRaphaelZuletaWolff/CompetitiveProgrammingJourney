#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,target;cin>>n;

    vector<ll> numeritos;

    vector<ll> prefix(n+1,0);

    map<ll,ll> mapita;

    ll mini = 10000000000;


    for (ll i = 1; i <= n; i++)
    {
        ll a; cin>>a;
        
        prefix[i] = prefix[i-1] + a;
        numeritos.push_back(a);

        mini = min(mini,a);
    }
    ll lu = 0;

    for (ll i = 0; i <= n; i++)
    {
        
        ll x = (abs(n*mini)+prefix[i])%n;
        // cout<<x<<endl;
        lu += mapita[x];
        mapita[x]++;
        
    }



    
    cout<<lu;
    




    
    return 0;
}