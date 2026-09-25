#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll t; cin>>t;

    while (t--)
    {
        double k,p,s; cin>>k>>p>>s;

        double aux = (s)/(k*(1+p/100));
        int res = static_cast<int>(aux);
        cout<<res<<endl;


    }
    


}