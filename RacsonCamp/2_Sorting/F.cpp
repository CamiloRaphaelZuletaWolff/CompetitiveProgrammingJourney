#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool abierto(char c){
    return c == '[' || c == '{' || c=='(';
}

bool contraparte(char abierto, char cerrado){
    return abierto == '(' && cerrado == ')' || abierto == '[' && cerrado == ']' ||abierto == '{' && cerrado == '}' ;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;


    map<ll,vector<string>>numeritos;

    for (ll i = 0; i < n; i++)
    {
        string s; cin>>s;

        numeritos[s.size()].push_back(s);
    }
    for(auto &a : numeritos){

        sort(a.second.begin(), a.second.end());
    }

    for(auto &a : numeritos){
        for( auto &b : a.second){

            cout<<b<<endl;
        }
    }
    
    return 0;

}