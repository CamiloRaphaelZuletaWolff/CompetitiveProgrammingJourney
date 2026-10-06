#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;
    
    vector<ll> numeritos;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        numeritos.push_back(x);
    }

    sort(numeritos.begin(),numeritos.end());
    ll target1 = 0;
    ll target2 = 0;

    if(n%2 == 1){
        target1 = numeritos[n/2];
    }else{
        target1 = numeritos[n/2];
        target1 = numeritos[n/2 -1];
    }

    ll aux1 = 0, aux2=0;

    for (ll i = 0; i < n; i++)
    {
        aux1 += abs(numeritos[i]-target1);
        aux2 += abs(numeritos[i]-target2);
    }

    cout<<min(aux1,aux2);
    

    return 0;
}