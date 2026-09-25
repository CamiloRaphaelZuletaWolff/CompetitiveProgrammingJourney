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
        rango actual = ranguito;
        rango anterior;
        if(it != setsito.begin()){
            
            auto it2 = it;
            it2--;
            anterior = *it2;
            bool roto = false;
            if(anterior.final >= actual.inicio && anterior.final > actual.final){
                roto = true;
                mapita[anterior.color] -= actual.final - actual.inicio +1LL;
                setsito.insert({anterior.inicio,actual.inicio-1,anterior.color});
                setsito.insert({actual.final+1, anterior.final,anterior.color});
                setsito.erase(it2);                
            }
            if(anterior.final >= actual.inicio && anterior.final == actual.final && !roto){
                roto = true;
                mapita[anterior.color] -= actual.final - actual.inicio +1LL;
                setsito.insert({anterior.inicio,actual.inicio-1,anterior.color});
                // setsito.insert({actual.final, anterior.final});
                setsito.erase(it2);                
            }
            
            if(anterior.final >= actual.inicio && !roto){
                it2 =setsito.erase(it2);
                mapita[anterior.color] -= anterior.final - anterior.inicio + 1LL;
                setsito.insert({anterior.inicio,actual.inicio-1,anterior.color});
            }
        }
        while (it != setsito.end())
        {
            
            actual = *it;
            if(actual.inicio >= ranguito.inicio && actual.final <= ranguito.final){
                mapita[actual.color] -= actual.final - actual.inicio +1;
                it = setsito.erase(it);
                if(ranguito.final == actual.final){
                    break;
                }
                
                
                continue;
            }

            if(actual.inicio >= ranguito.inicio && actual.final > ranguito.final){
                mapita[actual.color] -= ranguito.final - actual.inicio + 1;
                setsito.insert({ranguito.final+1,actual.final,actual.color});
                it = setsito.erase(it);
                break; 
            }
            



        }
        mapita[x] += ranguito.final - ranguito.inicio +1;
        
        setsito.insert(ranguito);
        
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