#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
// typedef unsigned long long ull;

ll target;

vector<pair<ll,ll>> numeritos;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n>>target;

    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        numeritos.push_back({a,i});
    }
    
    sort(numeritos.begin(),numeritos.end());

    for (ll k = 0; k < n; k++)
    {
        auto [actual,index]  = numeritos[k];
        ll x = target - actual;

        if(x < 0){
            continue;
        }
        vector<pair<ll,ll>> parejitas = numeritos;


        pair<ll,ll> lu = {-1,-1};

        ll i =0, j = n-1;


        while (i !=j)
        {
            if(index == parejitas[i].second){
                i++;
                continue;
            }
            if(index == parejitas[j].second){
                j--;
                continue;
            }
            ll primero = parejitas[i].first;
            ll ultimo = parejitas[j].first;

            if(primero + ultimo == x){
                lu = {parejitas[i].second, parejitas[j].second};
                break;
            }


            if(primero + ultimo < x){
                i++;
                continue;
            }

            if(primero + ultimo > x){
                j--;
                continue;
            }
        }

        if(lu.first != -1){
            cout<<index+1<<" "<<lu.first+1<<" "<<lu.second+1;
            return 0;
        }

        
        

    }
    

    cout<<"IMPOSSIBLE";
    
    
    

    return 0;
}