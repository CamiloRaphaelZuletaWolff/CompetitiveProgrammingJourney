#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct ganadores {

    ll longitud;
    ll inicio;

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    ll t; cin>>t;

    for (ll k= 1; k <= t;  k++)
    {
        ll n; cin>>n;

        vector<ll> numeritos(n-1);

        for (ll i = 0; i < n-1; i++)
        {
            cin>>numeritos[i];
        }


        vector<ll> dp(n,0);

        ll inicio = 1;

        ll l = 0, r = 0, mayor = -1000000000000000;


        for (ll i = 1; i < n; i++)
        {
            if(numeritos[i-1] >  dp[i-1] + numeritos[i-1]){
                dp[i] = numeritos[i-1];
                inicio = i;
            }else{
                dp[i] = dp[i-1] + numeritos[i-1];
            }

            ll actual = i - inicio +1;
            ll campeon = r -l +1;

            if(mayor < dp[i] || dp[i] == mayor && actual > campeon){
                l = inicio;
                r = i;
                mayor = dp[i];
            }
        }

        if(mayor <= 0) {
            cout<<"Route "<< k<< " has no nice parts"<<endl;
            continue;
        }else{
            cout << "The nicest part of route "<<k<<" is between stops "<<l<<" and "<<r+1<<endl;
        }
        

        
        



        
        
    }
    
    
    
    
    
    return 0;

}