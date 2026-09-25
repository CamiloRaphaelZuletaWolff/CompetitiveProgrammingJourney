#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll m,s;cin >>m >>s;

    if(s < m || s > m*9){
        cout<<-1<<" "<<-1;
        return 0;
    }

    ll cociente = s/9;
    ll resto = s%9;

    vector<ll>res(m,0);

    for (ll i = 0; i < s/9; i++)
    {
        res[i]= 9;
    }
    bool f = 0;
    if(m*cociente != s){
        res[m-1] = resto;
    }

    bool val = 0;

    for (ll i = m-1; i >=0; i--)
    {
        if(res[i]!= 0){
            val = true;
        }
        if(res[i]== 0 && !val){
            continue;
        }
        
        cout<<res[i];
    }
    
    cout<<" ";
    for (ll i = 0; i < m; i++)
    {
        cout<<res[i];
    }
        
    
    

    cout<<"\n";    
    

    return 0;

}