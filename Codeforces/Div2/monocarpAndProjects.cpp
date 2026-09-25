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
        ll a,b,k; cin >>a>>b>>k;
        if(a == b){
            cout<<0<<endl;
            continue;
        }

        ll aux = b-2*a;
        ll acc = 0;

        if(aux < 0){

            cout<< k * (b%a)<<endl;

            continue;

        }
        ll lu = 0;
        
        while (acc < k)
        {
            
            if(acc == (aux)) break;

            acc++;

            lu += b % a;

            b++;
            a++;

        }

        if(aux+1 <= k){
            a++;b++;

            lu += (k - (aux)-1) * (b%a);
        }

        cout<<lu<<endl;
        
    }

    return 0;

}