#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

struct nodo
{
    ll valor;
    ll indice;


    bool operator<( const nodo a) const{

        return valor == a.valor ? indice < a.indice : valor < a.valor;
    
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n,m;cin>>n>>m;
    set<ll> st;
    vll numeritos(n);

    set<nodo> noditos;
    set<nodo> noditosCopia;
    ll maxi = -10;
    for (ll i = 0; i < n; i++)
    {
        ll x ; cin>>x;
        maxi = max(maxi, x);
        numeritos[i] = x;
        st.insert(x);
        noditos.insert({x,i});
    }
    
    vll copia = numeritos; 
    
    reverse(copia.begin(), copia.end());

    for (ll i = 0; i < n; i++)
    {
        noditosCopia.insert({copia[i],i});   
    }
    
    ll izq = 0, indexI = -1;
    ll der = 0, indexD = -1;

    ll lu = 0;

    while(izq != maxi && der != maxi){
        
        auto it = noditosCopia.begin();
        
        auto it2 = st.upper_bound(der);

        if(it2 == st.end()) break;

        ll siguiente = *st.upper_bound(der); 

        while(it != noditosCopia.end()){

            it2 = st.upper_bound(der);
            if(it2 == st.end()) break;

            siguiente = *st.upper_bound(der); 

            it = noditosCopia.upper_bound({der,indexD});

            if(it == noditosCopia.end()) break;

            nodo actual = *it;

            if(actual.valor != siguiente || actual.indice < indexD){
                break;
            }

            der = actual.valor;
            indexD = actual.indice;
            
        }

        it = noditos.begin();

        while(it != noditos.end()){
            
            
            it2 = st.upper_bound(izq);
            if(it2 == st.end()) break;

            siguiente = *st.upper_bound(izq);


            it = noditos.upper_bound({izq,indexI});
            
            if(it == noditos.end()) break;

            nodo actual = *it;

            if(actual.valor != siguiente || actual.indice < indexI){
                break;
            }

            izq = actual.valor;
            indexI = actual.indice;

        }


        if(izq > der){

            der = izq;
        }else{

            izq = der;
        }
        lu++;
        indexD = -1;
        indexI = -1;

    }

    cout<<st.size() <<" "<< lu<<endl;
    
    









    return 0;
}