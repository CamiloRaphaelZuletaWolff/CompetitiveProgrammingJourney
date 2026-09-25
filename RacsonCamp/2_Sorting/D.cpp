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

    vector<equipo> mapita(3*n+1,{0,0,0});
    
    vector<bool> marcados(3*n +1,false);
    // set<ll>disponibles;

    vector<ll> todos;


    for (ll i = 0; i < 3*n; i++)
    {
        cin>>rankings[i];
    }

    todos = rankings;

    sort(todos.begin(),todos.end());

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
        ll actual = rankings[i];

        if(!marcados[actual]){
            capitanes.insert(actual);
            marcados[actual] = true;
        }

        equipo x = mapita[actual];

        marcados[x.a] = true;
        marcados[x.b] = true;        
        marcados[x.c] = true;
        
        
        if(actual == candidato) break;      
    }

    vector<ll> marc;
    vector<ll> notMarc;

    for (ll i = 1; i < marcados.size(); i++)
    {
        if(marcados[i]){
            marc.push_back(i);
        }
    }
    // cout<<"++++++++++"<<endl;

    sort(marc.begin(), marc.end());


    if(!capitanes.count(candidato)){

        for(ll x: todos){
            if(x == candidato) continue;
            cout<<x<<" ";
        
        }
        return 0;
    }


    ll a = mapita[candidato].a, b = mapita[candidato].b, c = mapita[candidato].c; 

    bool x = false, y = false, z = false, roto = true;

    
            if(candidato == a) x =true;
            
            if(candidato == b) y =true;
            
            if(candidato == c) z =true;
    for (ll i = 0; i < marc.size(); i++)
    {
        if(x && y && z){
            marcados[marc[i]] = false;
            roto = true;
        }else{

            if(marc[i] == a) x =true;
            
            if(marc[i] == b) y =true;
            
            if(marc[i] == c) z =true;

        if(marc[i] == candidato)continue;
            cout<< marc[i] <<" ";
        }
    }
    
    for (ll i = 1; i < marcados.size(); i++)
    {
        if(!marcados[i]){
            notMarc.push_back(i);
        }
    }

    sort(notMarc.begin(), notMarc.end());

    for(ll x : notMarc){

        if(x == candidato)continue;
        cout<< x<< " ";
    }

    






    
    
    
    
    
    return 0;

}