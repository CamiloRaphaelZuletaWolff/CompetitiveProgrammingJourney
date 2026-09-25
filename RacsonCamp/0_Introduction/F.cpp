#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    ll t; cin>>t;

    while (t--)
    {
        ll a,b,l,n;cin>>a>>b>>l>>n;

        cout<<b*(2*(n-1)) + 2*l + (2*n-1)*a<< endl;
        // cout<<(n/k)*k << endl;


    }
    


}