#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll t; cin>>t;

    while(t--){
        ll n; cin>>n;

        string s; cin>>s;
        stack<ll> pilita;
        // cout<<n<<" "<<s<<endl;

        set<ll>usados;
        for (ll i = 0; i < s.size(); i++)
        {
            char actual = s[i];

            if(actual =='1'){
                // cout<<i+1<<endl;
                pilita.push(i+1);
                continue;
            }
            if(actual == '2'){
                if(!pilita.empty()){
                    // cout<<"gafdsa"<<endl;
                    ll aux = pilita.top();
                    usados.insert(aux);
                    pilita.pop();
                }else{    
                    // cout<<"sfdasfdasdasdsa"<<endl;
                    usados.insert(i+1);
                }
            }
            if(actual == '3'){
                usados.insert(i+1);
            }
            
        }

        cout<<n- usados.size()<<endl;
        for (ll i = 1; i <= n; i++)
        {
            if(!usados.count(i)) cout<< i<<" ";
        }
        
        cout<<endl;
        
        
        
    }
    return 0;

}