#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n, x; cin>>n>>x;

    ll lu = n;

    multiset<ll> multiSetsito;

    vector<ll> numeritos;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;

        numeritos.push_back(x);

        multiSetsito.insert(x);
        
    }
    sort(numeritos.begin(),numeritos.end(),greater<ll>());

    for (ll i = 0; i < n; i++)
    {
        ll actual = numeritos[i];
        if(!multiSetsito.count(actual)) continue;
        multiSetsito.erase(multiSetsito.find(actual));
        ll objetivo = x - numeritos[i];
        
        auto it = multiSetsito.lower_bound(objetivo);

        ll aux = -1;

        if(it != multiSetsito.end()){
            aux = *it;
            if(aux == objetivo){
                lu--;
                multiSetsito.erase(it);
                continue;
            }
        }
        

        ll contador = multiSetsito.count(actual);


        if(it == multiSetsito.begin()) continue;

        it--;


        ll opcion = *it;
        
        if(opcion < objetivo){
            lu--;
            multiSetsito.erase(it);
        }







    }

    cout<<lu<<endl;
    

    
    
    

    


    return 0;
}