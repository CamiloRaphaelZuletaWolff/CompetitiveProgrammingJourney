#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void llenar (vector<string> &binarios){

    for (ll i = 0; i < binarios.size(); i++)
    {
        if(i < binarios.size()/2){
            binarios[i] = "1";
        }else{
            binarios[i] = "0";
        }
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    vector<string> actual;

    actual.push_back("1");
    actual.push_back("0");

    for (ll j = 2; j <= n; j++)
    {

        vector<string> nuevo(2 * actual.size());

        llenar(nuevo);

        // cout<< "asadsadas "<<j-1 << endl;
        // for(string s : actual){
        //     cout<<s<<endl;
        // }


        for (ll i = 0; i < actual.size(); i++)
        {

            nuevo[i] += actual[i]; 

            // cout<<i<<" xdddd "<<nuevo[i]<<endl;
        }

        ll aux = actual.size() -1;
        for (ll i = actual.size(); i < 2*actual.size(); i++)
        {
            nuevo[i] +=actual[aux];

            aux--;
        }
        
        

        actual = nuevo;
        
    }

    for(string s : actual){
        cout<<s<<endl;
    }

    return 0;
    

}