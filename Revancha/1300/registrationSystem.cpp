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

    map<string,ll> repetidos;

    ll n; cin>>n;

    for (ll i = 0; i < n; i++)
    {
        string s ;cin>>s;

        if(repetidos[s] == 0){
            cout<<"OK"<<endl;
            repetidos[s]++;
        }else{
            cout<<s<<repetidos[s]<<endl;
            repetidos[s]++;
        }


    }
    

    return 0;

}