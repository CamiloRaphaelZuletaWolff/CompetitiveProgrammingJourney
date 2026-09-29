#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);



    ll n; cin>>n;

    map<string,ll> mapita;

    for (ll i = 0; i < n; i++)
    {
        string s; cin>>s;

        if(mapita[s] == 0){
            cout<<"OK" << endl;

        }else{
            cout<< s <<mapita[s]<<endl;
        }
        mapita[s]++;

        
    }
    

    return 0;

}