#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);


    ll x; cin>>x;
    ll n = 3*3*3*3;
    

    vector<ll> lu (100000000+1,0);

    lu[0] = 0;
    lu[1] = 2;
    lu[2] = 3;
    lu[3] = 6;


    for (ll i = 1; i < n; i++)
    {
        if(lu[i] != 0){
            lu[lu[i]] = i *3;
        }else{
            ll l = lu[i-1], r;
            lu[i] = l+1;
            lu[i+1] = l+2;
            i--;
        }
    }


    for (ll i = 0; i < lu.size(); i++)
    {

        if(lu[i] != 0)
        cout<<i<<" "<<lu[i]<<endl;
    }
    
    cout<<lu[x];
    
    
    

    return 0;

}