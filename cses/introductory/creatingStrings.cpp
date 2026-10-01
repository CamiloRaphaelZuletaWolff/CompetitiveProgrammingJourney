#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



string s;
set<string> lu;

map<char,ll> mapita;

ll contar(char c, string palabra){
    ll contador = 0;
    for (ll i = 0; i < palabra.size(); i++)
    {
        if(palabra[i] == c) contador++;
    }

    return contador;
}


void solve(ll n, string acumulado){
    // cout<<n<<endl;
    if(n == s.size()){
        lu.insert(acumulado);
        return;
    }

    for (ll i = 0; i < s.size(); i++)
    {
        if(contar(s[i],acumulado)< mapita[s[i]])solve(n+1,acumulado + s[i]);
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    cin>>s;

    for (ll i = 0; i < s.size(); i++)
    {
        mapita[s[i]]++;
    }

    for(auto [a,b] : mapita){

        if(b == s.size()){
            cout<<1<<endl<<s<<endl;
            return 0;
        }

    }
    

    solve(0,"");

    cout<<lu.size()<<endl;
    for(auto i : lu){

        cout<<i<<endl;

    }


    

    return 0;
    

}