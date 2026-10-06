#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    
    ll n,x; cin>>n>>x;

    vector<pair<ll,ll>> parejitas;

    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;

        parejitas.push_back({a,i});
    }

    sort(parejitas.begin(),parejitas.end());

    pair<ll,ll> lu = {-1,-1};

    ll i =0, j = n-1;


    while (i !=j)
    {
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
        cout<<min(lu.first +1,lu.second + 1) << " "<<max(lu.first +1,lu.second + 1);
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    
    
    

    return 0;
}