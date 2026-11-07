#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n,k; cin>>n>>k;
    
    map<ll,ll> apariciones;

    ll lu = 0;
    
    vector<ll> numeritos;
    
    ll left = 0;

    ll unicos = 0;
    ll totales = 0;
    

    for (ll i = 0; i < n; i++)
    {
        ll actual; cin>>actual;

        numeritos.push_back(actual);
        if(apariciones[actual] == 0){
            unicos++;
        }
        apariciones[actual]++;
        totales++;
        if(unicos > k){
            for (ll j = left; j < i; j++)
            {
                if(unicos <= k) break;
                ll a = numeritos[j];
                apariciones[a]--;
                totales--;
                if(apariciones[a] == 0){
                    unicos--;
                }
                left = j;
            }
            left++;
        }
        lu += totales;
    }

    cout<<lu;


    
    
    return 0;
}