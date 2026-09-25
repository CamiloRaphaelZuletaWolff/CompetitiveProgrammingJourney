#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    string s;cin>>s;

    char op ='x';
    ll index = 0;


    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i]== '/'||s[i]== '-'||s[i]== '*'||s[i]== '+'){
            op = s[i];
            index =i;
            break;
        }
        
    }

    string primero = s.substr(0,index);
    string segundo = s.substr(index+1,s.size()-index-1);

    ll a = stoll(primero);
    ll b = stoll(segundo);

    if(op == '*') cout << a*b;
    if(op == '+') cout << a+b;
    if(op == '-') cout << a-b;
    if(op == '/') cout << a/b;
    


}