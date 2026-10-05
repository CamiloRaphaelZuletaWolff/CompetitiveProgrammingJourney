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

    }

    ll t; cin>>t;

    while(t--){

        ll q; cin>>q;

        string aux= to_string(q);

        if(aux.size() == 1){
            cout<< aux<<endl;
            continue;
        }


        for (ll i = 1; i < n; i++)
        {
            auto [a,b] = digitos[i];



            if(q <= b){


                if(a == 2){

                    string s = "x";
                    
                    for (ll i = 1; i <= 99; i++)
                    {
                        string s1 = to_string(i);

                        s += s1;
                    }

                    cout<<s[q]<<endl;
                    break;


                }



                ll primero = power(10,a-1);

                ll numero = q-digitos[a-2].second;
                
                ll aux = primero + numero/a -1;
                
                // cout<<q<<" ENTREEEEEE "<<b<<endl;
                
                // cout<<primero <<" aaaaaa "<<numero <<endl;
                // cout<< aux<<" queFuncione "<<endl;
                if(numero%a == 0){
                    string lu = to_string((aux));
                    cout<<lu[a-1]<<endl;
                }else{
                    string lu = to_string((aux+1));
                    cout<<lu[((numero)%a)-1]<<endl;
                }
                break;


            }

            


        }









    }



    

    return 0;
    

}