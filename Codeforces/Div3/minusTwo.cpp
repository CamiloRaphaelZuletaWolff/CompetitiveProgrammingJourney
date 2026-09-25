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
        
        ll n; cin>>n;

        ll a = 0, b = 0,c =0;

        for (ll i = 0; i < n; i++)
        {
            ll x; cin>>x;

            if(x % 2== 1){
                a++;
            }else{

                if((x/2)%2 == 1){
                    b++;
                }else{
                    c++;
                }
            }


        }
        cout<< max({a,b,c})<<endl;
    }
    return 0;

}