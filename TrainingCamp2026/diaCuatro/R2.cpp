#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string numero; cin>>numero;
    ll k; cin>>k;

    for (ll i = 0; i < numero.size(); i++)
    {
        char maxi = numero[i]; 
        ll index = i;
        
        for (ll j = i; j <= k+i && j < numero.size(); j++)
        {
            char actual = numero[j];
            if(actual>maxi){
                maxi = actual;
                index = j;
            }

             
        }
        for (int j = index; j > i; j--)
        {
            swap(numero[j],numero[j-1]);
        }
        k-=index-i;
        
    }
    cout<<numero<<"\n";
    
    return 0;

}