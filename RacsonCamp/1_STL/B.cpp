#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    stack<ll> pilita;
    for (ll i = 0; i < n; i++)
    {
        string s; cin>>s;

        if(s == "*" || s == "/" || s == "-" || s == "+"){
            ll a = pilita.top();
            pilita.pop();
            ll b = pilita.top();
            pilita.pop();
            ll res = 0;
            if(s == "*"){
                res = b*a;
            }
            if(s == "+"){
                res = b+a;
            }
            if(s == "-"){
                res = b-a;
            }
            if(s == "/"){
                res = b/a;
            }
            pilita.push(res);
            

        }else{

            ll x = stoll(s);
            pilita.push(x);



        }     

         
    }
    
    cout<<pilita.top();
    






    return 0;

}