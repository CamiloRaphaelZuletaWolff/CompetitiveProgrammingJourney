#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool valido (vector<ll> &a){
    
    for (ll i = 0; i < a.size(); i++)
    {
        if(a[i] == 1 && i != a.size()-1){
            return true;
        }
    }
    
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<ll> numeritos (1000+1,0);
    
    ll aux = 10000 - n;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        numeritos[aux] = x;
        aux++;
    }
    
    ll res = 0;

    while(valido(numeritos)){

        ll ayuda = numeritos.size()-1;
        if(numeritos[ayuda] == 1){
            

        }
        res++;




    }



    
    return 0;

}