#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


ll MOD = 1000000;

struct equipo{

    ll a;
    ll b;
    ll c;

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<ll> rankings(3*n);

    map<ll,equipo> mapita;
    
    set<ll> marcados;
    set<ll>disponibles;

    set<ll> todos;


    for (ll i = 0; i < 3*n; i++)
    {
        cin>>rankings[i];
        disponibles.insert(rankings[i]);
        
        todos.insert(rankings[i]);
    }

    for (ll i = 0; i < n; i++)
    {
        ll a,b,c;cin>>a>>b>>c;
        mapita[a] = {a,b,c};
        mapita[b] = {a,b,c};
        mapita[c] = {a,b,c};
    }

    ll candidato; cin>>candidato;
    
    set<ll> capitanes;


    for (ll i = 0; i < 3*n; i++)
    {

        if(marcados.size() == 3*n) break;
        ll actual = rankings[i];

        if(!marcados.count(actual)){
            capitanes.insert(actual);
        }

        equipo x = mapita[actual];

        marcados.insert(x.a);
        marcados.insert(x.b);        
        marcados.insert(x.c);

        
        disponibles.erase(x.a);
        disponibles.erase(x.b);        
        disponibles.erase(x.c);

        if(actual == candidato) break;      
    }


    if(!capitanes.count(candidato)){

        for(ll x: todos){
            if(x == candidato) continue;
            cout<<x<<" ";
        
        }
        return 0;

    }

    set<ll> impresos;

    impresos.insert(candidato);

    bool necesarios = false;

    ll a = mapita[candidato].a, b = mapita[candidato].b, c = mapita[candidato].c; 

    // cout<< a<<" "<<b<< " "<<c<<endl;
    vector<ll> res;


    // cout<<endl;


    for(ll x : marcados){
        if(impresos.count(a)&&impresos.count(b) && impresos.count(c)){
            // cout<<"++++++++++++++"<<endl;
            res.push_back(x);
            necesarios = true;

        }else{
            if(x == candidato) continue;
            cout<<x << " ";
            impresos.insert(x);
        }        
    }

    if(!necesarios){

        for(ll x: disponibles){
            if(x == candidato) continue;
            cout<<x<<" ";
        }

    }else{
        for(ll x: disponibles){
            if(x == candidato) continue;
            res.push_back(x);
        }

        sort(res.begin(), res.end());

        for(ll ojala : res){
            if(ojala == candidato) continue;
            cout<<ojala<< " ";
        }


    }



    





    
    
    
    
    
    return 0;

}