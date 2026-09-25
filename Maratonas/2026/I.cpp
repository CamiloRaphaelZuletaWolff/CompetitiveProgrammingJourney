#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct amigo{
    ll id;
    ll frecuencia;
};

struct rango {

    ll l;
    ll r;
    ll freq;
};
               


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll f, n; cin>>f>>n;

    vector<amigo> amigos;
    map<ll,rango> rangos;
    map<ll,ll> freqs;

    for (ll i = 0; i < n; i++)
    {

        ll id, frecuencia; cin>>id>>frecuencia;
        
        amigos.push_back({id,frecuencia});

        freqs[id] = frecuencia;
    }

    map<ll,vector<ll>> grafo;



    vector<ll> aceptados;

    for (ll i = 0; i < n; i++)
    {
        char c; cin>>c;
        if(c == 'T'){
            ll x; cin>>x;
            grafo[x].push_back(amigos[i].id);
        }
        if(c == 'A'){
            ll l, r; cin>>l>>r;
            aceptados.push_back(amigos[i].id);
            rangos[amigos[i].id] = {l,l+r,amigos[i].frecuencia};
        }
    }
    
    map<ll,bool> vis;

    for (ll i = 0; i < aceptados.size(); i++)
    {
        stack<ll> pilita;
        
        pilita.push(aceptados[i]);
        ll freq = 0;
        while(!pilita.empty()){

            ll tope = pilita.top();
            pilita.pop();
            if(!vis[tope]){
                freq += max(1LL, freqs[tope]);
            }
            vis[tope] = true;

            auto& hijos = grafo[tope];

            for (ll j = 0; j < hijos.size(); j++)
            {
                if(!vis[hijos[j]]){
                    pilita.push(hijos[j]);
                }
            }            
        }

        rango aux = rangos[aceptados[i]]; 
        rangos[aceptados[i]] = {aux.l,aux.r,freq};

    }

    // for(auto [amigo,range] : rangos){

    //     cout<< amigo<<" "<< range.l<<" "<<range.r<<" "<<range.freq<<endl;
    // }
    
    vector<pair<ll,ll>> eventos;

    for (auto& [id, r] : rangos) {
        eventos.push_back({r.l,  r.freq});
        eventos.push_back({r.r, -r.freq});
    }

    sort(eventos.begin(), eventos.end());

    ll aux = 0, lu = 0;
    for (auto [t, d] : eventos) {
        aux += d;
        lu = max(lu, aux);
    }

    cout << lu << endl;


    // topoSort(grafo);

    




    


    
    
    
    

    return 0;

}