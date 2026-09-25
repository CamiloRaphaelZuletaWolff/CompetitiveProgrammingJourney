#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n,k; cin>>n>>k;




    vector<ll> colita;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        colita.push_back(x);
    }

    if(k > n){
        cout<<n;
        return 0;
    }
    ll contador = 1;
    ll actual = colita[0];
    ll seguidas = 0;

    while(seguidas != k)
    {
        // cout<<"aaaaaaaaaaa"<<endl;
        ll primero = actual;
        ll segundo = colita[contador];

        if(primero > segundo){
            colita.push_back(segundo);
            seguidas++;
        }else{
            colita.push_back(primero);
            actual = segundo;
            seguidas = 1;
        }
        



        contador++;
    }

    cout<<actual;
    

    return 0;

}