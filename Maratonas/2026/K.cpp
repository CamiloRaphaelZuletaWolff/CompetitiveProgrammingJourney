#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);


    ll n; cin>>n;

    vector<ll> stock(n), piezas(n);
    
    ll mini = LLONG_MAX;
    ll index = -1;
    
    for (ll i = 0; i < n; i++)
    {
        cin>>stock[i];

    }
    
    for (ll i = 0; i < n; i++)
    {
        cin>>piezas[i];

    }

    for (ll i = 0; i < n; i++)
    {
        if(piezas[i]> stock[i]){
            cout<<-1;
            return 0;
        }
    }


    ll lu = 0;
    
    for (ll i = 0; i < n; i++)
    {
        lu += stock[i];

        mini = min(mini, stock[i] - piezas[i]);



    }

    // cout<<mini<<endl;
    cout<<lu - mini;
    
    
    
    
    

    return 0;

}