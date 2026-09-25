#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;





void solve(ll n, char origen, char destino){

    if(n == 0) return;

    char faltante;

    if(origen == 'A' && destino == 'B') faltante = 'C';
    if(origen == 'A' && destino == 'C') faltante = 'B';
    if(origen == 'C' && destino == 'B') faltante = 'A';
    if(origen == 'B' && destino == 'A') faltante = 'C';
    if(origen == 'B' && destino == 'C') faltante = 'A';
    if(origen == 'C' && destino == 'A') faltante = 'B';
    

    solve(n-1,origen,faltante);

    cout<<"Move from " << origen << " to " << destino<< "."<<endl;

    solve(n-1, faltante, destino);
    
    



}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while (t--)
    {
        ll x;
        char origen,destino;
        cin>>x>>origen>>destino;
        solve(x,origen,destino);
        cout<<"Done!" <<endl;
    }
    
    
    
    
    return 0;

}