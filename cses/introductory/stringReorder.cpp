#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


tuple <char,ll,char,ll> buscar(vector<ll> &letras){
    
    ll b,d=1000000;
    char a = 'x',c = 'x';
    for (ll i = 0; i < letras.size(); i++)
    {
        if(letras[i] == 0 ) continue;

        if(a == 'x'){
            a = (char)('A' + i);
            b = letras[i];
        }else{
            
            c = (char)('A' + i);
            d = letras[i];
            break;
            
        }
        
    }

    // cout<<"MUERTE A LOS PUNTEROS"<<endl;

    // cout<<a<<" "<< b<<" "<<c<<" "<<d<<endl;

    return {a,b,c,d};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    string s; cin>>s;


    vector<ll> letras (26,0);

    for (ll i = 0; i < s.size(); i++)
    {
        letras[s[i] - 'A']++;
    }
    // cout<<"Muerte al greedy"<<endl;
    // for (ll i = 0; i < 26; i++)
    // {
    //     cout<<(char)('A' + i)<<" "<<letras[i]<<endl;
    // }
    // cout<<"Lets see"<<endl;
    

    string aux; 

    for (ll i = 0; i < s.size();)
    {

        auto [a,b,c,d] = buscar(letras);
        ll b1 = b,d1 = d; 
        for (ll j = 0; j < b1+d1; j++)
        {
            // cout<<b<<" "<<d<<" "<<j<<endl;
            if(b == 0 || d == 0) break;

            if(j%2== 0){
                aux.push_back(a);
                letras[a-'A']--;
                b--;
            }else{
                if(c=='x')continue;
                aux.push_back(c);
                letras[c-'A']--;
                d--;
            }
            i++;
        }        
    }
    // cout<<aux.size()<<endl;
    // cout<<s.size()<<endl;
    // cout<<aux<<endl;
    
    char actual = aux[aux.size()-1];
    ll contador = 0;

    for (ll i = aux.size()-2; i >=0; i--)
    {
        if(aux[i] != actual) break;
        contador++;
    }

    // cout<<contador<<endl;

    if(contador == 0){
        cout<<aux;
        return 0;
    }



    // cout<<aux<<endl;

    // cout<<aux[aux.size()-1-contador]<<endl;

    ll index = 0;

    for (ll i = 0; i < aux.size(); i++)
    {
        if(aux[i] == actual){
            index = i;
            break;
        }
    }


    ll copia = contador;
    string lu;

    // cout<<copia<<endl;
    for (ll i = index-1; i >= 0;i--)
    {
        if(copia !=0){
            lu.push_back(aux[i]);
            lu.push_back(actual);
            copia--;
        }else{
            lu.push_back(aux[i]);
        }
    }

    reverse(lu.begin(),lu.end());


    for (ll i = index; i < aux.size()-contador; i++)
    {
        lu.push_back(aux[i]);
    }
    
    if(lu.size() != s.size()){
        cout<<-1<<endl;
        return 0;
    }

    // cout<<lu<<endl;

    string siSePuede;

    for (ll i = 0; i < lu.size(); i++)
    {
        if(lu[i] == actual){
            index = i;
            break;
        }
    }
    

    for (ll i = max(index-1,0LL); i < lu.size()-1; i++)
    {
        if(lu[i] != actual) siSePuede.push_back(lu[i]);
    }

    sort(siSePuede.begin(),siSePuede.end());
    ll lloroSiDa=0;

    ll necesitoAyuda = 0;
    for (ll i = max(index-1,0LL); i < lu.size()-1; i++)
    {
        if(lloroSiDa == siSePuede.size() )break;
        if(lu[i] != actual){
            if(lu[i-1]==siSePuede[lloroSiDa]){
                // necesitoAyuda++;
                // lloroSiDa--;
                // i--;

                for (ll putaVida = lloroSiDa; putaVida < siSePuede.size(); putaVida++)
                {
                    if(siSePuede[putaVida] != lu[i-1]){
                        swap(siSePuede[putaVida], siSePuede[lloroSiDa]);                        break;
                    }
                }
            }
            if(lu[i-1]!=siSePuede[lloroSiDa]){
                lu[i] = siSePuede[lloroSiDa];
            } 
            lloroSiDa++;    
        }
    }
    
    // cout<<aux<<endl;
    cout<<lu;
    





    
    






    


    




    return 0;

}