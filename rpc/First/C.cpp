#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


struct noche{

    ll comida;
    ll inicio;
    ll duracion;


};


vector<noche> noches; 


vector<pair<ll,ll>> eventos;

    double EPS = 1e-12;

bool posible(double n,double personas){

    double EPS = 1e-12;
    priority_queue<pair<ll,double>, vector<pair<ll,double>>, greater<pair<ll,double>>> pq;

    for (ll i = 1; i <= noches.size(); i++)
    {
        pq.push({noches[i-1].duracion,(double)noches[i-1].comida});

        double falta = personas * n;
        while (falta > EPS && !pq.empty())
        {
            pair<ll,double> x = pq.top();
            double cant = x.second;
            ll f = x.first; 
            pq.pop();
            double toma = min(falta,(double)cant);
            falta-= toma;
            cant -= toma;

            if(cant>EPS) pq.push({f,cant});
        }
        if(falta > EPS) return false;
    }

    return true;
    






    

}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll n; cin>>n;
    double p; cin>>p;




    for (ll i = 1; i <= n; i++)
    {

        ll x,y; cin>>x>>y;

        noches.push_back({x,i,y});

    }

    for (ll i = 0; i < n; i++)
    {

        auto [a,b,c] = noches[i];

        eventos.push_back({b,a});
        eventos.push_back({b+c,-a});
        
    }

    sort(eventos.begin(), eventos.end());



    double left = 0.0, right = 1e16;
    for (ll i = 0; i < 50; i++)
    {
        double mid = left + (right - left) / 2.0;    

        if(posible(mid,p)){
            left = mid;
        }else{
            right = mid;
        }

    }

    if(left - EPS < 0){
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<fixed<< setprecision(9)<<left<<endl;
    
    



    return 0;
}