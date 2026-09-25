#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct nodo
{
    ll l;
    ll r;
    bool buenChango;
};

vector<bool> vis(100000+5,false);


ll dfs (vector<vector<nodo>> &grafo, nodo inicio){

    stack<nodo> pilita;

    pilita.push(inicio);

    ll lu = 0;

    while (!pilita.empty())
    {
        nodo actual = pilita.top();

        pilita.pop();

        if(vis[actual.l]) continue;

        vis[actual.l] = true;
        

        if(!actual.buenChango){
            lu++;
        }
        
        for (ll i = 0; i < grafo[actual.l].size(); i++)
        {
            nodo vecino = grafo[actual.l][i];

            if(!vis[vecino.l]){

                pilita.push(vecino);

            }
        }


    }
    return lu;
    

    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,m; cin >>n>>m;

    string s (n+2,'0');

    for (ll i = 1; i <= n; i++)
    {
        char x; cin>>x;
        s[i] = x;
    }
    


    vector<nodo> nodos(n+2);
    ll contador = 0;

    for (ll i = 0; i < n+1; i++)
    {

        nodos[i] = {i, i+1, s[i] == s[i+1]}; 

        contador += s[i] != s[i+1];
    }

    vector<vector<nodo>> grafo (n+2);

    for (ll i = 0; i < m; i++)
    {
        ll l, r; cin>>l>>r;

        grafo[l-1].push_back({r,r+1,nodos[r].buenChango});
        grafo[r].push_back({l-1,l,nodos[l-1].buenChango});
    
    }


    bool roto = false;

    ll lu = 0;

    for(auto nodo : grafo){
        for(auto [l,r,buenChango] : nodo){

            if(!vis[l]){

                ll aux = dfs(grafo,{l,r,buenChango});

                if(aux % 2 == 0){
                    lu+= aux;
                }else{
                    roto = true;
                    break;
                }
            }
        }
        if(roto) break;

        
    }

    if(roto || lu != contador){

        cout<<"NO";
        return 0;
    }

    if(lu == contador){
        
        cout<<"YES";

    }
    


    




    return 0;

}