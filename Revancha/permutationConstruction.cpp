#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct elemento
{
    ll pos;
    ll valor;


    bool operator<(const elemento a) const{
        return valor > a.valor;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){

        ll n; cin>>n;

        vector<elemento>prefix(n,{1,0});

        for (ll i = 1; i < n; i++)
        {
            ll x;cin>>x;
            prefix[i] ={ i+1 , x + prefix[i-1].valor};
            
        }
        
        ll inutil; cin>>inutil;

        sort(prefix.begin(), prefix.end());


        vector <ll> lu(n+1);

        for (ll i = 0; i < n; i++)
        {
            lu[prefix[i].pos] = i+1;

        }

        for (ll i = 1; i < n+1; i++)
        {
            cout<< lu[i] << " ";
        }
        
        cout<<endl;



        



        
    }

    return 0;

}