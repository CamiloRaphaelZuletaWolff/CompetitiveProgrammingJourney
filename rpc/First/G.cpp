#include <bits/stdc++.h>
using namespace std;
typedef int ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n, v; cin>>n>>v;

    v*= 5;
    vector<ll> problemas(n);

    for (ll i = 0; i < n; i++)
    {
        cin>>problemas[i];
    }

    sort(problemas.begin(), problemas.end());

    ll lu = 0;
    for (ll i = 0; i < n; i++)
    {
        if(v >= problemas[i]){
            v-=problemas[i];
            lu++;
        }
    }

    cout<<lu<<endl;
    
    

    return 0;

}