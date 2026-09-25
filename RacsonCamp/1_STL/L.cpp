#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n;cin>>n;


    ll acumulado = 0;
    ll acumulado2 = 0;

    priority_queue<ll> maxi;
    priority_queue<ll,vector<ll>,greater<ll>> mini; 

    ll topeMaxi = 100000000000;
    ll topeMini = 100000000000;
    ll contador1 = 0;
    ll contador2 = 0;
    ll contador = 0;


    bool equilibrio = false;



    for (ll i = 0; i < n; i++)
    {
        ll tipo; cin>>tipo;

        if(tipo == 1) {


            ll a,b; cin>>a>>b;

            acumulado  += b;
            acumulado2 += a;
            // contador++;


            if(maxi.empty()){ 
                maxi.push(a);
                topeMaxi = maxi.top();
                contador1 += a;
                continue;
            }

            if(maxi.size()==mini.size()){

                if(a <= topeMaxi){
                    maxi.push(a);
                    topeMaxi = maxi.top();
                    contador1 += a;
                }else{
                    mini.push(a);
                    topeMini = mini.top();
                    contador2 += a;
                }
                continue;
            }

            if(maxi.size() > mini.size()){
                if(a >= topeMaxi){
                    mini.push(a);
                    topeMini = mini.top();
                    contador2 += a;
                }else{
                    contador1 -= maxi.top();
                    maxi.pop();

                    maxi.push(a);
                    contador1+=a;


                    mini.push(topeMaxi);
                    contador2+=topeMaxi;
                    topeMaxi= maxi.top();
                    topeMini = mini.top();
                }
            }

            if(maxi.size() < mini.size()){
                if(a <= topeMini){
                    maxi.push(a);
                    topeMaxi = maxi.top();
                    contador1+=a;
                }else{
                    contador2-=mini.top();
                    mini.pop();
                    mini.push(a);
                    contador2 += a;

                    maxi.push(topeMini);

                    contador1 += topeMini;
                    topeMaxi= maxi.top();
                    topeMini = mini.top();
                }
            }
        }else{

            // cout<<i<<endl;

            if(maxi.size() > mini.size()){
                // contador1 -= 
                // cout<< topeMaxi <<" " <<(contador * topeMaxi) - contador1 + contador2 - contador * topeMaxi + acumulado<<endl;

                cout<< topeMaxi << " "<<(long long)maxi.size()*topeMaxi - contador1 - (long long)mini.size()*topeMaxi + contador2 + acumulado<<endl;
                continue; 
            }

            if(maxi.size() < mini.size()){
                // cout<<topeMini <<" " << abs((contador * topeMini) - contador2) + contador1 - contador * topeMini + acumulado<<endl;
                cout<<topeMini<<" "<< (long long)maxi.size()*topeMini - contador1 - (long long)mini.size()*topeMini + contador2 + acumulado<<endl;
                continue;
            }
            
            cout<< topeMaxi << " "<<(long long)maxi.size()*topeMaxi - contador1 - (long long)mini.size()*topeMaxi + contador2 + acumulado<<endl;

                // cout<< topeMaxi << " "<< contador2 -contador1<<endl;
            // cout<< topeMaxi <<" " <<abs((contador * topeMaxi) - contador1) + contador2 - contador * topeMaxi + acumulado<<endl;


        }
    }

        // while (!maxi.empty())
        // {
        //     ll z; z =maxi.top();
        //     maxi.pop();

        //     cout<<z<<" ";

        // }
        // cout<<endl;


        // while (!mini.empty())
        // {
        //     ll z; z =mini.top();
        //     mini.pop();

        //     cout<<z<<" ";

        // }
        // cout<<endl;

        
        

    
    


    


    
    return 0;

}