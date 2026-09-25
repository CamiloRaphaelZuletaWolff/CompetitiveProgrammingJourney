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

    while (n--)
    {
        string s; cin>>s;

        stack<char> pilita;
        pilita.push(s[0]);


        bool roto = false;

        char previo = pilita.top();
        for (ll i = 1; i < s.size(); i++)
        {
            if(abierto(s[i])){
                pilita.push(s[i]);
            }else{
                if(pilita.empty() || !contraparte(previo,s[i])){
                    roto = true;
                }else{
                    pilita.pop();
                }


            }
            if(!pilita.empty())
            previo = pilita.top();
        }

        if(!roto && pilita.empty()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
        
    }
    

    return 0;

}