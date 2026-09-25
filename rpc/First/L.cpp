#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    ll n , l,r; cin>>n>>l>>r;


    ll maxi = -1000000, mini = 10000000;

    for (ll i = 0; i < n-1; i++)
    {
        ll x; cin>>x;

        maxi = max(maxi, x);

        mini = min (mini, x);

    }

    vector<ll> lu;

    // cout<<mini << " " << maxi<<endl;

    for (ll i = l; i <= r; i++)
    {
        if(min(mini,i) == l  && max(maxi,i) == r){
            lu.push_back(i);
        }
    }

    if(lu.size() == 0 ){
        cout<<-1;
    }else{
        for (ll i = 0; i < lu.size(); i++)
        {
            if(i != 0) cout<<" ";
            cout<<lu[i];
        }
        
    }
    
    cout<<endl;
    
    
    

    return 0;

}