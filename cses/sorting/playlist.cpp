#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n ; cin >>n;
    

    map<ll,ll> parejitas;

    set<ll> apariciones;

    ll lu = 0;
    
    ll esperado = 1;

    ll index = 0;

    vector<ll> numeritos;

    vector<bool> vis(n,0);

    for (ll i = 0; i < n; i++)
    {
        ll actual; cin>>actual;
        // cout<<"siempreEstoyBien "<<i<<" "<<lu<<endl;
        // cout<<"ELEMENTOS"<<endl;

        // for(auto a: apariciones){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        numeritos.push_back(actual);

        if(!apariciones.count(actual)){
            apariciones.insert(actual);
            parejitas[actual] = i;
            lu = max(lu,(ll)apariciones.size());
            continue;
        }

        // cout<<i<<" "<<actual<<endl;
        
        lu = max(lu,(ll)apariciones.size());
        
        // cout<<i<<" dasjdasdadj "<<endl;
        for (ll j = parejitas[actual]; j >= 0; j--)
        {
            if(vis[j]) break;

            // cout<<"Entreeee "<<j<<" "<<numeritos[j]<<endl;
            apariciones.erase(numeritos[j]);
            vis[j] = true;
        }
        parejitas[actual] = i;
        apariciones.insert(actual);        
        lu = max(lu,(ll)apariciones.size());


    }

    cout<<max(lu,(ll)apariciones.size());


    
    
    return 0;
}