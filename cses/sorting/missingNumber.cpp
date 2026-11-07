#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;

    vector<ll>numeritos(n);


    for (ll i = 0; i < n; i++)
    {
        cin>>numeritos[i];
    }
    
    sort(numeritos.begin(), numeritos.end());

    ll anterior = 0;
    ll lu = 0;

    for (ll i = 0; i < n; i++)
    {
        ll actual = numeritos[i];

        if(actual <= lu+1){
            lu += actual;
        }else{
            cout<<lu + 1 ;
            return 0;
        }

        







        // if(lu+1 < numeritos[i]){
        //     cout<<lu+1;
        //     return 0;
        // }
        
        // lu += actual;

        // anterior = actual;

        // if(actual == anterior || anterior == actual-1){
        //     lu+=actual;
        // }


        
    }

    cout<< lu+1<<endl;
    


    
    
    
    

    return 0;
}