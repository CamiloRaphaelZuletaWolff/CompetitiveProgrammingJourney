#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s; cin>>s;

    ll lu = 1;

    ll contador = 1;

    char anterior = s[0];

    for (ll i = 1; i < s.size(); i++)
    {
        char actual = s[i];
        
        if(actual == anterior){
            contador++;
        }else{
            // cout<<i<<" "<<contador<<endl; 
            lu = max(lu,contador);
            contador = 1;
            anterior = actual; 
        }   
    }

    cout<<max(lu,contador);
    
    

    return 0;

}