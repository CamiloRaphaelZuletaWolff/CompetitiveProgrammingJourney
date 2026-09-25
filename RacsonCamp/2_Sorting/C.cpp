#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct participante {

    string nombre;
    ll region;
    ll puntuacion;


    // bool operator<(const participante a){
    //     return puntuacion < a.puntuacion;
    // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n; cin>>n;

    vector<ll> numeritos(n);

    // numeritos[n/2] = 1;
    ll dos = 1;
    ll uno = 0;

    if(n % 2 == 1){
        for (ll i = 0; i < n; i++)
        {
            if(i <= n/2){
                numeritos[i] = n - 2*i;
            }else{
                numeritos[i] = 2*dos;
                dos++;
            }
        }
    }else{
        for (ll i = 0; i < n; i++)
        {
            if(i < n/2){
                numeritos[i] = n - 2*i;
            }else{
                numeritos[i] = 1 + 2*uno;
                uno++;
            }
            
        }
        
    }
    for (ll i = 0; i < n; i++)
    {
        cout<<numeritos[i]<< " ";
    }
    
    
    
    

    return 0;

}