#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;




ll res = 100000000000000;


ll gcd(ll a,ll b){

    if(b == 0){
        return a;
    }
    
    return gcd(b, a % b );
}


ll f(ll izquierda, ll derecha, ll pasos){
    
    if(izquierda == 1 && derecha == 1) return pasos;
    
    
    return f(derecha, izquierda % derecha, pasos + izquierda / derecha);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    if(n == 1){
        cout<<0;
        return 0;
    }

    for (ll i = 1; i < n; i++)
    {
        if(gcd(n,i) == 1){
            ll aux = f(n,i,0);
            
            // cout<< i<<" "<< aux<<endl;
            res = min(res,aux);
        }
    }

    cout<<res<<endl;


    
    
    
    return 0;

}