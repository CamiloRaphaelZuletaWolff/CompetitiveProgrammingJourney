#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    ll k1; cin>>k1;

    vector<ll>pilita1,pilita2;

    for (ll i = 0; i < k1; i++)
    {
        ll x; cin>>x;
        pilita1.push_back(x);
    }
    ll k2 ;cin>>k2;
    
    for (ll i = 0; i < k2; i++)
    {
        ll x; cin>>x;
        pilita2.push_back(x);
    }

    ll elementos1 = pilita1.size(), index1 =0;
    
    ll elementos2 = pilita2.size() ,index2 = 0;

    bool ganador = true;
    bool roto = false;

    ll juegos = 0;

    while (elementos1 != 0 && elementos2 != 0)
    {

        if(juegos == 10000){
            roto = true;
            break;
        }
        if(pilita1[index1] > pilita2[index2]){
            pilita1.push_back(pilita2[index2]);
            pilita1.push_back(pilita1[index1]);
            elementos1 ++;
            elementos2--;
            
        juegos++;
            if(elementos2 == 0){
                ganador = true;
                break;
            }
            index1++;
            index2++;
        }else{
            pilita2.push_back(pilita1[index1]);
            pilita2.push_back(pilita2[index2]);
            elementos1--;
            elementos2++;
            
        juegos++;

            if(elementos1 == 0) {
                ganador = false;
                break;
            }
            index1++;
            index2++;
        }
        
    }

    if(roto){
        cout<<-1<<endl;
        return 0;
    }

    cout<<juegos<< " ";

    if(ganador){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }

    
    
    return 0;

}