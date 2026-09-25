#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n, t; cin>>n>>t;

    vector<pair<ll,ll>> b;

    vector<ll>diferencias;
    
    for (ll i = 0; i < n; i++)
    {
        ll x,y;cin>>x>>y;
        b.push_back({x,y});
    }

    sort(b.begin(),b.end(), [] (const pair<ll,ll> a, pair<ll,ll> b){
        return a.second > b.second;
    });

    priority_queue<ll>colita;

    ll res = 0;
    ll agarrados = 0;

    ll contador = 0;

    while(agarrados != t)
    {
        if(colita.empty()){
            res += b[contador].second;            
            // cout<<"++++++++++++++"<<endl;
            // cout<<b[contador].first<<" " <<b[contador].second<<endl; 
            
            colita.push(b[contador].first- b[contador].second);
            contador++;
            agarrados++;
        }else{
            // cout<<"==========="<<endl;
            // cout<<colita.top() <<" " <<b[contador].second<<endl; 
            if(colita.top() >  b[contador].second || contador == n){
                res += colita.top();
                colita.pop();
                agarrados++;
            }else{
                
                res += b[contador].second;
                // contador++;
                colita.push(b[contador].first- b[contador].second);
                agarrados++;
                contador++;

            }
        }
    }

    cout<<res;

    
    

    return 0;

}