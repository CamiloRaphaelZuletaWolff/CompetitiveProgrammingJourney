#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool valido(ll a,ll b, vector<ll> lu1, vector<ll> lu2){

    ll a1 = 0,b1 = 0;

    for (ll i = 0; i < lu1.size(); i++)
    {
        if(lu1[i] > lu2[i]){
            a1++;
            continue;
        }
        if(lu2[i] > lu1[i]){
            b1++;
            continue;
        }
    }

    return a1==a && b1 == b;
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){

        ll n, a,b;
        cin>>n>>a>>b;

        if(a+b > n){
            cout<<"NO"<<endl;
            continue;
        }

        ll empates= n - a - b;

        if(empates == n){
            cout<<"YES"<<endl;
            for (ll i = 0; i < n; i++)
            {
                cout<<i+1<<" ";
            }
            cout<<endl;
            for (ll i = 0; i < n; i++)
            {
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
            
        }
        
        
        set<ll> usados;


        ll aux = (empates-1)/2;
        ll cont = 0;
        for (ll i = n/2 - aux; cont < empates; i++)
        {
            usados.insert(i);
            cont++;
        }

        // for(auto a: usados){
        //     cout<< a<<endl;
        // }
        // cout<<"Yo siempre estoy bien"<<endl;

        vector<ll> lu1;
        vector<ll> lu2;


        for(auto a : usados){
            lu1.push_back(a);
            lu2.push_back(a);
        }

        for (ll i = 1; i <= n; i++)
        {
            if(!usados.count(i))lu1.push_back(i);
        }

        // cout<<"Siempre estoy bien"<<endl;

        cont = 0;

        // for (ll i = n-b+1; cont < b;)
        // {
        //     if(!usados.count(i)){
        //         lu2.push_back(i);
        //         cont++;
        //     } 
        //     i++;
        // }
        // cout<<"Nunca me fui"<<endl;

        vector<ll>ayudaaaa;

        for (ll i = 1; i <= n; i++)
        {
            if(!usados.count(i)){
                ayudaaaa.push_back(i);
            }
        }

        for (ll i = ayudaaaa.size() - b; i < ayudaaaa.size(); i++)
        {
            lu2.push_back(ayudaaaa[i]);

        }
        
        


        cont = 0;

        for (ll i = 1; cont < a;)
        {
            if(!usados.count(i)){
                lu2.push_back(i);
                
                cont++;
            } 
            i++;
        }

        if(!valido(a,b,lu1,lu2)){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;

        for (ll i = 0; i < n; i++)
        {
            cout<<lu1[i]<<" ";
        }
        cout<<endl;
        
        for (ll i = 0; i < n; i++)
        {
            cout<<lu2[i]<<" ";
        }
        cout<<endl;

    }

    return 0;

}