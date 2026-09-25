#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct participante {

    string nombre;
    ll region;
    ll puntuacion;


    // bool operator<(const participante a){
    //     return puntuacion < a.puntuacion;
    // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n,m; cin>>n>>m;

    vector<participante> participantes;

    vector<vector<participante>> porRegion(m+1);


    for (ll i = 0; i < n; i++)
    {
        
        string s; cin>>s;
        ll r,p;cin>>r>>p;
        // cin>>s>>r>>p;
        participante x = {s,r,p};
        participantes.push_back(x);

    }
    
    sort(participantes.begin(),participantes.end(), [](participante a, participante b) {
        return a.puntuacion<b.puntuacion;
    });

    for (ll i = n-1; i >= 0; i--)
    {
        porRegion[participantes[i].region].push_back(participantes[i]);
    }

    for (ll i = 1; i <= m; i++)
    {
        // cout<<"++++++++++++++++++"<<

        participante primero = porRegion[i][0];
        participante segundo = porRegion[i][1];

        if(primero.puntuacion == segundo.puntuacion){
            cout<< "?"<<endl;
            continue;
        }

        if(porRegion[i].size() >= 3 && porRegion[i][2].puntuacion == segundo.puntuacion){
            cout<< "?" << endl;
            continue;
        }

        cout<<primero.nombre << " "<< segundo.nombre<< endl;




        
        
    }
    
    

    
    

    return 0;

}