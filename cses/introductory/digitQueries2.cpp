#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll power (ll x, ll n){
    ll res =1 ;
    for (ll i = 0; i < n; i++)
    {
        res *=x;
    }
    return res;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n = 17; 

    ll res = 0;


    vector<pair<ll,ll>> digitos;

    for (ll i = 0; i <= n; i++)
    {
        res+= 9 * power(10,i) * (i+1);
        digitos.push_back({i+1,res});

        cout<<i+1 << " "<< res<<endl;

    }


    string s = "x";

    for (ll i = 1; i <= 999; i++)
    {
        string s1 = to_string(i);

        s += s1;
    }

    cout<<s.size()<<endl;
    cout<<s[19]<<endl;
    for (ll i = 2869; i <= 2871; i++)
    {
        cout<<s[i];
    }
    


    

    return 0;
    

}