#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



struct rango {
    ll inicio;
    ll final;
    ll color;


    bool operator<(const rango &a) const {
        return inicio < a.inicio;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);


    ll l,c,n; cin>>l>>c>>n;

    map<ll,ll> mapita;

    set<rango> setsito;

    setsito.insert({0,l-1,1});

    mapita[1] = l;

    for (ll i = 0; i < n; i++)
    {
        ll p,x,a,b; cin>>p>>x>>a>>b;
        ll s = mapita[p];
        ll m1 = (a + s*s)%l;
        ll m2 = (a + (s+b)*(s+b))%l;
        
        rango ranguito = {min(m1,m2),max(m1,m2),x};

        auto it = setsito.lower_bound(ranguito);
        auto it2 = it;


        if(it2 != setsito.begin()){

            it2--;

            rango a = *it2;

            if(a.final >= ranguito.inicio){
                setsito.erase(it2);
                if(a.final > ranguito.final){
                    setsito.insert({ranguito.final +1, a.final, a.color});
                    mapita[a.color] -= ranguito.final - ranguito.inicio + 1;
                }else{
                    mapita[a.color] -= a.final - ranguito.inicio + 1;
                }
                setsito.insert({a.inicio,ranguito.inicio-1,a.color}); 
                
            }
        }

        while (it != setsito.end())
        {
            rango b = *it;
            
            if(b.inicio >= ranguito.final+1) break;

            if(b.final > ranguito.final){
                setsito.insert({ranguito.final+1,b.final,b.color});
                
                mapita[b.color] -= ranguito.final - b.inicio +1;
            }else{
                mapita[b.color] -= b.final - b.inicio + 1;
            }
            
            it = setsito.erase(it);
        }

        mapita[ranguito.color] += ranguito.final - ranguito.inicio +1;
        setsito.insert({ranguito.inicio,ranguito.final,ranguito.color});
    }

    ll res = -100000000000000000;

    for(pair<ll,ll> tremendo : mapita){

        if(res <= tremendo.second){
            res = tremendo.second;

        }
    }

    cout<<res<<endl;
    








    


    return 0;

}