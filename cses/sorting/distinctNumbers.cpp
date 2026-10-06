#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n; cin>>n;

    set<ll> lu;

    for (ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        lu.insert(x);
    }

    cout<<lu.size();
    


    return 0;
}