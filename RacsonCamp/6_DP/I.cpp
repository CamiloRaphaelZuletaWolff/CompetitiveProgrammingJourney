#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct objeto{
    ll valor;
    ll peso;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    
    ll n, w; cin>>n>>w;

    vector<objeto> cosas;

    for (ll i = 0; i < n; i++)
    {
        ll x,y,z; cin>>x>>y>>z;

        ll aux =0;

        for (ll i = 1; aux < z;)
        {
            
            aux += i;

            // cout<<aux<<endl;
            if(aux <= z){
                cosas.push_back({i*x,i*y});
            }else{
                aux -= i;
                break;
            }
            i = i*2;
        }

        // cout<<"============="<<endl;

        if(z - aux != 0){

            // cout<<z<<" "<<aux<<endl;
            // cout<<"+++++++++++++++++++++++++++++"<<endl;
            cosas.push_back({(abs(z-aux))*x,abs((z-aux))*y});
        }        
    }

    // for(auto i : cosas){

    //     cout<< i.peso <<" " << i.valor<<endl;
    // }

    // cout<<"--------------------"<<endl;

    vector<ll> dp(w+1,0);


    for (ll i = 0; i < cosas.size(); i++)
    {
        for (ll j = w; j >= 1; j--)
        {
            if(j- cosas[i].peso >= 0)
            dp[j] = max(dp[j], dp[j-cosas[i].peso] + cosas[i].valor);
            
        }
        
    }
    

    cout<<dp[w];
    


    

    return 0;

}