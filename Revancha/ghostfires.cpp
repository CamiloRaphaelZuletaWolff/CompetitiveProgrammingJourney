#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct elemento
{
    char color;
    ll valor;


    bool operator<(const elemento a) const{
        return valor > a.valor;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t; cin>>t;
    while(t--){

        ll r, g, b; cin>>r>>g>>b;


        vector<elemento> elementos;

        elementos.push_back({'R',r});
        
        elementos.push_back({'G',g});
        
        elementos.push_back({'B',b});
        
        // string res(r+g+b, 'x');

        vector<char> lu (r+g+b+3, 'x');

        sort(elementos.begin(),elementos.end());

        ll i = 3;



        while (true)
        {
            if(elementos[0].valor == 0 && elementos[1].valor == 0 && elementos[2].valor == 0){
                break;
            }
            
            

            if(lu[i-1] != elementos[0].color && lu[i-3] != elementos[0].color){
                elementos[0].valor--;
                lu[i] = elementos[0].color;
            }else{
                if(lu[i-1] != elementos[1].color && lu[i-3] != elementos[1].color && elementos[1].valor != 0){
                   elementos[1].valor--;
                   
                    lu[i] = elementos[1].color;
                }else{
                    if(lu[i-1] == elementos[2].color && lu[i-3] == elementos[2].color || elementos[2].valor == 0){
                        break;
                    }
                    
                    elementos[2].valor--;
                    
                    lu[i] = elementos[2].color;
                }
            }
            i++;
            sort(elementos.begin(),elementos.end());

        }

        for (ll i = 0; i < lu.size(); i++)
        {
            if(lu[i] !='x'){
                cout<<lu[i];
            }
        }

        cout<<endl;
        
        
        



    }
    return 0;

}