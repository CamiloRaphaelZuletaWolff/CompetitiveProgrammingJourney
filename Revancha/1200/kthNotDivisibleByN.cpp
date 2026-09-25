#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double eps = 1e-9;

vector<double> numeritos;


struct rango {

    double l;
    double r;

};


bool f(double distancia, double l){

    vector<rango> rangos;


    for (ll i = 0; i < numeritos.size(); i++)
    {
        double a = numeritos[i];

        rangos.push_back({a-distancia, a + distancia});
        
    }

    for (ll i = 0; i < rangos.size()-1; i++)
    {
        rango actual = rangos[i];

        if(rangos[i].r - rangos[i+1].l < eps){

            return false;
        }


    }

    if(rangos[0].l > eps){
        return false;
    }

    if(rangos[rangos.size()-1].r - l < eps){
        return false;
    }

    
    


    




    return true;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){

        ll n,k; cin>>n>>k;

        ll aux = k / (n-1);

        ll lu = aux * n + (k % (n-1));

        if(k % (n-1) == 0){
            lu--;
        }

        cout<< lu <<endl;
    }
    return 0;

}