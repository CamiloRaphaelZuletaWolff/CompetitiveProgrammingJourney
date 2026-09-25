#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    ll n; cin>>n;

    vector<pair<ll,ll>> tasks(n);

    for (ll i = 0; i < n; i++)
    {
        ll a,b; cin>>a>>b;
        tasks[i] = {a,b};
    }

    sort(tasks.begin(),tasks.end());

    ll res = 0, tiempo = 0;

    for (ll i = 0; i < n; i++)
    {
        tiempo +=tasks[i].first;
        res+= tasks[i].second - tiempo;    
    }
    cout<<res;
    
    
    return 0;

}