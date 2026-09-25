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

    string lu;  cin>>lu;

    // if(lu == "0"){
    //     cout<<0;
    //     return 0;
    // }
    ll i =0;
    if(lu[0] == '0'){

        lu[0] = '9';
        i++;
    }

    for (;i < lu.size(); i++)
    {
        if(lu[i] == '5'){
            lu[i] = '4';
        }
        if(lu[i] == '6'){
            lu[i] = '3';
        }
        if(lu[i] == '7'){
            lu[i] = '2';
        }
        if(lu[i] == '8'){
            lu[i] = '1';
        }
        if(lu[i] == '9' && i != 0){
            lu[i] = '0';
        }

    }

    cout<<lu;
    

    
    return 0;

}