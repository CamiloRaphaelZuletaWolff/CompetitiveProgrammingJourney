#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


vector<string> lu;


void solve(ll n, ll origen, ll destino){

    if(n == 0) return;

    ll faltante;

    if(origen == 1 && destino == 3) faltante = 2;
    if(origen == 3 && destino == 2) faltante = 1;
    if(origen == 2 && destino == 1) faltante = 3;
    if(origen == 1 && destino == 2) faltante = 3;
    if(origen == 2 && destino == 3) faltante = 1;
    if(origen == 3 && destino == 1) faltante = 2;
    

    solve(n-1,origen,faltante);

    lu.push_back(to_string(origen) + " " + to_string(destino));

    solve(n-1, faltante, destino);
    
    



}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    solve(n,1,3);

    cout<<lu.size()<<endl;

    for(string s: lu){
        cout<<s<<endl;
    }
    
    
    
    
    return 0;

}