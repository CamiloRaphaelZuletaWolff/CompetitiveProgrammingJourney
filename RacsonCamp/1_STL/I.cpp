#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll contador = 0;
ll l;
ll limite = 0;

bool roto = false;


ll power(ll base, ll exp) {
    ll res = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base);
        }
        base = (base * base);
        exp /= 2;
    }
    return res;
}


ll calcularValor(stack<ll> pilita){

    ll aux = 0;
    ll ultimo;

    if(roto) return 0;
    while (!pilita.empty())
    {
        if(pilita.size() == 1) {
            ultimo = pilita.top();
            break;
        }
        aux+=pilita.top();
        pilita.pop();


    }


    if(aux *ultimo >= limite){
        roto = true;
    }


    return aux*ultimo;
    
}

ll solveFor(){

    ll n; cin>>n;

    ll aux = 0;

    stack<ll> pilita;
    pilita.push(n);

    while (contador != l)
    {
        string s; cin>>s;
        if(s == "add"){
            pilita.push(1LL);
            contador++;
            continue;
        }
        if(s == "for"){
            contador++;
            ll aux = solveFor();
            pilita.push(aux);
            continue;
        }
        if(s == "end"){
            contador++;
            break;
        }
    }

    return calcularValor(pilita);
    

    
    



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    cin>>l;

    ll x = 0;

    limite = pow(2,32);

    while(contador != l)
    {
        string s; cin>>s;

        if(s == "add"){
            x++;
            contador++;
        }

        if(s == "for"){
            contador++;
            x += solveFor();
        }

    }


    if(x >= limite || roto){
        cout<<"OVERFLOW!!!"<<endl;

    }else{
        cout<<x<<endl;
    }
    


    return 0;

}