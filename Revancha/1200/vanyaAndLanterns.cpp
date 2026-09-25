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

    ll n; cin>>n;

    double l; cin>>l;


    for (ll i = 0; i < n; i++)
    {
        double x;cin>>x;

        numeritos.push_back(x);
    }

        sort(numeritos.begin(),numeritos.end());


    double left = 0.0, right = l;
    
    
    // while (right - left > eps* max(1.0, right)) {
    for (ll i = 0; i < 80; i++)
    {
        double mid = left + (right - left) / 2.0;    
        if (f(mid,l)){ 
            right = mid; 
        }else{
            left = mid;  
        }
    // }
    }

    cout<<fixed<<setprecision(10)<<left<<endl;



    return 0;

}