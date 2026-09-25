#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);


    ll n; cin>>n;

    vector<ll>numeritos(1e6 + 1,0);

    ll maxi = LLONG_MIN;


    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;

        maxi = max(x,maxi);

        numeritos[x]++;

    }

    // ll x = 0; 
    // for(auto i : numeritos){
    //     cout<<x<<" "<<i<<" ";
    //     x++;
    // }

    // cout<<endl;
    ll res = 1;


    for (ll i = maxi; i >= 1; i--)
    {
        ll contador = 0;

        ll candidato = i;

        ll aux = 1;

        while(((candidato * aux) <= maxi)){

            // cout<<candidato<< " " << candidato* aux <<endl;

            contador += numeritos[candidato* aux];

            if(contador >= 2){
                res = candidato;
                break;
            }

            // cout<<"Contador: "<<contador<<endl;
            
            aux++;
            
            // cout<<candidato<< " " << candidato* aux <<endl;
        }
        if(res != 1){
            break;
        }        
    }

    cout<<res<<endl;
    




    


    return 0;

}