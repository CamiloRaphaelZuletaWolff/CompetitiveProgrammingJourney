#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
 
    ll n; cin>>n;

    vector<pair<ll,ll>> numeritos;

    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        numeritos.push_back({a,i});    
    }

    sort(numeritos.begin(),numeritos.end());



    ll lu =1;

    auto [previo,index] = numeritos[0];
    
    for (ll i = 1; i < n; i++)
    {
        auto [actual,indice] = numeritos[i];
        if(indice < index){
            lu++;
        }
        previo = actual;
        index = indice;
    }
    
    cout<<lu<<endl;
    
 
 
 
 
 
    
    
    
 
    return 0;
}