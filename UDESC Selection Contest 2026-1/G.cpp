#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    

    ll n; cin>>n;

    ll denominador = 100;

    for (ll i = 2; i <= 100; i++)
    {
        if(n % i == 0 && denominador % i == 0){

            while(n % i == 0 && denominador % i == 0){
                n/=i;
                denominador/=i;
            }
        }
        
    }
    // cout<<
    cout<<denominador;
    
    return 0;

}