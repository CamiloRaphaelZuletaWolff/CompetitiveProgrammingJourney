#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
// typedef unsigned long long ull;

ll target;

bool f(ll tiempo, vector<ll> &maquinas){
    ll lu = 0;

    for (ll i = 0; i < maquinas.size(); i++)
    {
        lu += tiempo/maquinas[i];
    }
    // cout<<"Funcion "<<tiempo<<" "<<lu<<endl;
    return lu >= target;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n>>target;
    vector<ll> maquinas;
    ll maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        maxi = max(maxi,a);
        maquinas.push_back(a);
    }

    ll left = 0, right = maxi * target;

    while(left < right){
        
        ll mid = (left + right) /2;

        // cout<< left<<" "<<mid << " "<< right<<endl;
        
        if(f(mid,maquinas)){
            right = mid;
        }else{
            left = mid+1;
        }
    }

    cout<<left;
    



    return 0;
}