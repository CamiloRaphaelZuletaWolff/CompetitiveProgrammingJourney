#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n ; cin>>n;
    vector<string>cadenas;
    
    for (ll i = 0; i < n; i++)
    {
        string s; cin>>s;
        cadenas.push_back(s);
    }
    sort(cadenas.begin(), cadenas.end(), [](const string & s, const string & t){
        return s + t < t+s;
    });

    string res; 
    for (ll i = 0; i < n; i++)
    {
        res = res + cadenas[i];
    }

    cout<<res;
    
    

    return 0;

}