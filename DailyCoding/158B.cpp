#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n;

    cin>>n;

    map<ll,ll> mapita;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        mapita[x]++;
    }

    ll lu = mapita[4];

    lu += min(mapita[3],mapita[1]);
    
    // cout<<"---------------" << lu << endl;
    ll aux = min(mapita[3],mapita[1]);
    mapita[3] -= aux;
    
    mapita[1] -= aux;

    lu += mapita[3];

    lu += mapita[1] /4;
    
    lu += mapita[2] /2;

    // cout<<"++++++++++" << lu << endl;

    mapita[1] %= 4;

    mapita[2] %= 2;


    // cout<<mapita[1] << " " << mapita[2]<<endl;

    if(mapita[1] == 0 && mapita[2] == 0){
        cout<< lu<<endl;
        return 0;
    }

    if(mapita[1] + mapita[2] *2 > 4 ) {
        lu+= 2;
    }else{
        lu+= 1;
    }


    cout<< lu<<endl;









    
    

    return 0;

}