#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    ll n;cin>>n;
    vector<ll> X;
    vector<ll> Y;
    for (int i = 0; i < n; i++)
    {
        ll x,y;cin>>x>>y;
        X.push_back(x);
        Y.push_back(y);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    ll R = X[n-1]-X[0]+2; 
    ll D = Y[n-1]-Y[0]+2; 
    ll res = R*2 + D*2;
    cout<<res<<"\n";
    return 0;

}