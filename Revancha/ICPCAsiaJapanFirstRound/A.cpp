#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll fuerza(ll c) {
    if (c == 2) return 15;
    if (c == 1) return 14;
    return c;             
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n;
    while(cin>>n && n != 0){

        ll lu = 0;
        bool roto = false;
        for (ll i = 0; i < n; i++)
        {
            ll x;cin>>x;

            lu = max(lu, fuerza(x));
            
        }

        if(lu == 15){
            cout<<2<<endl;
            continue;
        }
        if(lu == 14){
            cout<<1<<endl;
            continue;
        }

        cout<<lu<<endl;
        
        // cin>>n;
        
    }

    return 0;

}