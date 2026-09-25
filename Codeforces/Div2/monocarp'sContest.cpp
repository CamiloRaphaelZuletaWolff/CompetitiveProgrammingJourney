#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){
        ll n; cin >>n;
        vector<ll> innecesario;

        ll unos = 0, ceros = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x; cin>>x;

            innecesario.push_back(x);

            if(x == 1){
                unos++;
            }else{
                ceros++;
            }
        }

        if(ceros < 2){
            cout<<-1<<endl;
            continue;
        }

        if(innecesario[0] == 0 && innecesario[n-1] == 0){
            cout<< 0 <<endl;
        }else{
            if(innecesario[0] == 1 && innecesario[n-1] == 0 || innecesario[0] == 0 && innecesario[n-1] == 1){
                cout<< 1 <<endl;
            }else{
                cout<< 2 << endl;

            }

        }
        
    }


    return 0;

}