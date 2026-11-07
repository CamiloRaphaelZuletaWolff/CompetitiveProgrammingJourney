#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    
    ll n; cin>>n;

    deque<ll> numeritos;

    ll maxi = 0;
    ll lu = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a; cin>>a;
        lu +=a;
        maxi = max(maxi, a);
    }

    cout<<max(lu,2*maxi);
    



    return 0;
}