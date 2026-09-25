#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t; cin>>t;
    while(t--){
        
        ll n, k; cin>>n>>k;

        string s; cin>>s;

        ll contador =0, lu = 0;


        for (ll i = 0; i < n/k; i++)
        {
            // cout<<i<<" ++++++++"<<endl;
            bool aux = true;
            ll contador = 0;

            for (ll j = i * k; ;j++)
            {
                if(contador == k) break;
                if(s[j] == '0'){
                    aux = false;
                }
                
                contador ++;
            }

            lu += aux;
            

        }
        cout<<lu<<endl;
        
    }
    return 0;

}