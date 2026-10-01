#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> numeritos;

vector<ll> lu;

void solve(ll n, ll acumulado1,ll acumulado2){

    if(n == numeritos.size()){
        lu.push_back(abs(acumulado1 - acumulado2));
        return;

    }
    
    solve(n+1,acumulado1+numeritos[n],acumulado2);
    
    solve(n+1,acumulado1,acumulado2+numeritos[n]);
    
    



    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        numeritos.push_back(x);
    }

    solve(0,0,0);

    ll luFinal = LLONG_MAX;
    
    for(ll i : lu){
        luFinal = min(luFinal,i);
    }

    cout<<luFinal;


    

    return 0;
    

}